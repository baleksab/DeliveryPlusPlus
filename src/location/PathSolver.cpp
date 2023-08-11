//
// Created by C425 on 10/08/2023.
//

#include "PathSolver.h"

PathSolver::PathSolver(const int startingCity, const Path::Type type):startingCity(startingCity), type(type) {
    unordered_map<int, bool> visitedCity;

    for (auto &it : City::getCities()) {
        int u = it.first;
        distances[u] = INFINITE;
        previousCity[u] = UNDEFINED;
        previousPath[u] = nullptr;
        visitedCity[u] = false;
    }

    distances[startingCity] = 0;

    for (auto &it : City::getCities()) {
        int u = findMinimum(visitedCity);

        if (u == UNDEFINED)
            continue;

        visitedCity[u] = true;
        City *curCity = City::getCityById(u);

        for (auto &itt : curCity->getConnections()) {
            int v = itt.first;

            if (!visitedCity[v] && curCity->doesConnectionExist(v)) {
                Path *shortestPath = findAdequatePath(curCity, v);

                if (shortestPath != nullptr && isSmaller(distances[u] + shortestPath->getDistance(), distances[v])) {
                    distances[v] = distances[u] + shortestPath->getDistance();
                    previousCity[v] = u;
                    previousPath[v] = shortestPath;
                }
            }
        }
    }
}

const bool PathSolver::isSmaller(const double i, const double j) {
    if (i == INFINITE) return false;
    if (j == INFINITE) return true;

    return i < j;
}

const int PathSolver::findMinimum(unordered_map<int, bool> visitedCity) {
    double min = INFINITE;
    int minNode = UNDEFINED;

    for (auto &it : City::getCities()) {
        int u = it.first;

        if (!visitedCity[u] && isSmaller(distances[u], min)) {
            min = distances[u];
            minNode = u;
        }
    }

    return minNode;
}

void PathSolver::getPathTo(const int destinationCity) {
    if (!isCityReachable(destinationCity))
        throw CityNotReachable(startingCity, destinationCity, type);

    cout << "\n--------------------------------------------" << endl;
    cout << "Going from ";
    City::getCityById(startingCity)->getInfo();
    cout << " to ";
    City::getCityById(destinationCity)->getName();
    cout << "by " << Path::typeToString(type) << endl;

    reconstructPath(destinationCity);

    cout << "Destination reached! Total distance: " << distances[destinationCity];
    cout << " km\n--------------------------------------------" << endl;
}

void PathSolver::reconstructPath(const int destinationCity)  {
    if (previousCity[destinationCity] != UNDEFINED) {
        reconstructPath(previousCity[destinationCity]);
        previousPath[destinationCity]->getInfo();
    }

    cout << "\tCity: ";
    City::getCityById(destinationCity)->getInfo();
    cout << endl;
}

Path * PathSolver::findAdequatePath(City *curCity, const int destination) {
    Path *adequatePath = nullptr;

    vector<Path *> paths = curCity->getConnections()[destination];

    for (auto *path : paths)
        if ((type == Path::Type::ALL || type == path->getType()) && (adequatePath == nullptr || path->getDistance() < adequatePath->getDistance()))
            adequatePath = path;

    return adequatePath;
}

const bool PathSolver::isCityReachable(const int destination) {
    return previousCity[destination] != UNDEFINED;
}

