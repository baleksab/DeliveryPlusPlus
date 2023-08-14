//
// Created by C425 on 10/08/2023.
//

#include "PathSolver.h"

PathSolver::PathSolver(const int startingCity, const unordered_set<Path::Type> excludedPathTypes):startingCity(startingCity), excludedPathTypes(excludedPathTypes) {
    for (auto &it : City::getCities()) {
        int u = it.first;
        distances[u] = INFINITE;
        previousCity[u] = UNDEFINED;
        pathToCity[u] = nullptr;
        visitedCity[u] = false;
    }

    distances[startingCity] = 0;

    for (auto &it : City::getCities()) {
        int u = findMinimum();

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
                    pathToCity[v] = shortestPath;
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

const int PathSolver::findMinimum() {
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
    cout << "\n--------------------------------------------" << endl;
    cout << "Finding most optimal path from ";
    City::getCityById(startingCity)->getInfo();
    cout << " to ";
    City::getCityById(destinationCity)->getInfo();
    cout << endl;
    cout << "\t- Excluded path types: ";

    if (excludedPathTypes.empty())
        cout << " NONE";
    else
        for (const Path::Type &type : excludedPathTypes)
            cout << Path::typeToString(type) << " ";

    cout << endl;
    cout << "Calculating..." << endl;

    if (!isCityReachable(destinationCity)) {
        cout << "Path not found!" << endl;

        if (excludedPathTypes.empty())
            cout << "Concluding that it's impossible to reach this city, considering no exclusions!" << endl;
        else
            cout << "Consider removing some exclusions and trying again!" << endl;
    } else {
        cout << "Most optimal path found!" << endl;

        reconstructPath(destinationCity);

        cout << "Total distance: " << distances[destinationCity] << " km\n";
    }

    cout << "--------------------------------------------" << endl;
}

void PathSolver::reconstructPath(const int destinationCity)  {
    if (previousCity[destinationCity] != UNDEFINED) {
        reconstructPath(previousCity[destinationCity]);
        pathToCity[destinationCity]->getInfo();
    }

    cout << "\tCity: ";
    City::getCityById(destinationCity)->getInfo();
    cout << endl;
}

Path * PathSolver::findAdequatePath(City *curCity, const int destination) {
    Path *adequatePath = nullptr;

    vector<Path *> paths = curCity->getConnections()[destination];

    for (auto *path : paths) {
        bool notFiltered = true;

        for (const Path::Type &type : excludedPathTypes)
            if (type == path->getType()) {
                notFiltered = false;
                break;
            }

        if (!notFiltered)
            continue;

        if (adequatePath == nullptr || path->getDistance() < adequatePath->getDistance())
            adequatePath = path;
    }


    return adequatePath;
}

const bool PathSolver::isCityReachable(const int destination) {
    return previousCity[destination] != UNDEFINED;
}

