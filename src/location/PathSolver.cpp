//
// Created by C425 on 10/08/2023.
//

#include "PathSolver.h"

PathSolver::PathSolver(const int startingCity):startingCity(startingCity) {
    dijkstra(ALL_PATH_TYPES);
    dijkstra(Path::Type::ROAD);
    dijkstra(Path::Type::AIR);
    dijkstra(Path::Type::WATER);
    dijkstra(Path::Type::RAIL);
}

void PathSolver::dijkstra(const int type) {
    unordered_map<int, bool> visitedCity;

    allDistances[type] = unordered_map<int, double>();
    allPreviousCity[type] = unordered_map<int, int>();
    allPreviousPath[type] = unordered_map<int, Path *>();

    for (auto &it : City::getCities()) {
        int u = it.first;
        allDistances[type][u] = INFINITE;
        allPreviousCity[type][u] = UNDEFINED;
        allPreviousPath[type][u] = nullptr;
        visitedCity[u] = false;
    }

    allDistances[type][startingCity] = 0;

    for (auto &it : City::getCities()) {
        int u = findMinimum(allDistances[type], visitedCity);

        if (u == UNDEFINED)
            continue;

        visitedCity[u] = true;
        City *curCity = City::getCityById(u);

        for (auto &itt : curCity->getConnections()) {
            int v = itt.first;

            if (!visitedCity[v] && curCity->doesConnectionExist(v)) {
                Path *shortestPath = findAdequatePath(curCity, v, type);

                if (shortestPath != nullptr && isSmaller(allDistances[type][u] + shortestPath->getDistance(), allDistances[type][v])) {
                    allDistances[type][v] = allDistances[type][u] + shortestPath->getDistance();
                    allPreviousCity[type][v] = u;
                    allPreviousPath[type][v] = shortestPath;
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

const int PathSolver::findMinimum(unordered_map<int, double> distances, unordered_map<int, bool> visitedCity) {
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

void PathSolver::getPathTo(const int destinationCity, const Path::Type type) {
    cout << "\n--------------------------------------------" << endl;

    if (!isCityReachable(destinationCity, type)) {
        cout << "City ";
        City::getCityById(destinationCity)->getInfo();
        cout << " is impossible to reach from ";
        City::getCityById(startingCity)->getInfo();
        cout << " by " << Path::typeToString(type) << endl;
    } else {
        cout << "Going from ";
        City::getCityById(startingCity)->getInfo();
        cout << " to ";
        City::getCityById(destinationCity)->getInfo();
        cout << " by " << Path::typeToString(type) << endl;

        reconstructPath(type, destinationCity);

        cout << "Total distance: " << allDistances[type][destinationCity] << " km\n";
    }

    cout << "--------------------------------------------" << endl;
}

void PathSolver::getBestPathTo(const int destinationCity) {
    cout << "\n--------------------------------------------" << endl;

    if (!isCityReachable(destinationCity, ALL_PATH_TYPES)) {
        cout << "City ";
        City::getCityById(destinationCity)->getInfo();
        cout << " is impossible to reach from ";
        City::getCityById(startingCity)->getInfo();
    } else {
        cout << "Going from ";
        City::getCityById(startingCity)->getInfo();
        cout << " to ";
        City::getCityById(destinationCity)->getInfo();
        cout << " by all path types" << endl;

        reconstructPath(ALL_PATH_TYPES, destinationCity);

        cout << "Total distance: " << allDistances[ALL_PATH_TYPES][destinationCity] << " km\n";
    }

    cout << "--------------------------------------------" << endl;
}

void PathSolver::reconstructPath(const int type, const int destinationCity)  {
    if (allPreviousCity[type][destinationCity] != UNDEFINED) {
        reconstructPath(type, allPreviousCity[type][destinationCity]);
        allPreviousPath[type][destinationCity]->getInfo();
    }

    cout << "\tCity: ";
    City::getCityById(destinationCity)->getInfo();
    cout << endl;
}

Path * PathSolver::findAdequatePath(City *curCity, const int destination, const int type) {
    Path *adequatePath = nullptr;

    vector<Path *> paths = curCity->getConnections()[destination];

    for (auto *path : paths)
        if ((type == ALL_PATH_TYPES || type == path->getType()) && (adequatePath == nullptr || path->getDistance() < adequatePath->getDistance()))
            adequatePath = path;

    return adequatePath;
}

const bool PathSolver::isCityReachable(const int destination, const int type) {
    return allPreviousCity[type][destination] != UNDEFINED;
}

