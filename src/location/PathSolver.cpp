//
// Created by C425 on 10/08/2023.
//

#include "PathSolver.h"

PathSolver::PathSolver(const int startingCity, const unordered_set<Path::Type> includedPathTypes):startingCity(startingCity), includedPathTypes(includedPathTypes) {
    for (auto &it : City::getCities()) {
        int u = it.first;
        distances[u] = INFINITE;
        previousCity[u] = UNDEFINED;
        pathToPreviousCity[u] = UNDEFINED;
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
                const int pathID = findAdequatePath(curCity, v);

                if (pathID != UNDEFINED && isSmaller(distances[u] + Path::getPathById(pathID)->getDistance(), distances[v])) {
                    distances[v] = distances[u] + Path::getPathById(pathID)->getDistance();
                    previousCity[v] = u;
                    pathToPreviousCity[v] = pathID;
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
    cout << "Nalaženje najoptimalnijeg puta od ";
    City::getCityById(startingCity)->getInfo();
    cout << " do ";
    City::getCityById(destinationCity)->getInfo();
    cout << endl;
    cout << "\t- Dozvoljeni tipovi puteva: ";

    if (includedPathTypes.empty())
        cout << " SVI";
    else
        for (const Path::Type &type : includedPathTypes)
            cout << Path::typeToString(type) << " ";

    cout << endl;
    cout << "Računam..." << endl;

    if (!isCityReachable(destinationCity)) {
        cout << "Put nije nadjen!" << endl;

        if (includedPathTypes.empty())
            cout << "Zakljucujem da je nemoguce da se stigne do ovog grada, bilo kojim tipom veze!" << endl;
        else
            cout << "Probajte da dozvolite vise tipova veze!" << endl;
    } else {
        cout << "Najoptimalniji put pronadjen!" << endl;

        reconstructPath(destinationCity);

        cout << "Ukupno rastojanje: " << distances[destinationCity] << " km\n";
    }

    cout << "--------------------------------------------" << endl;
}

void PathSolver::reconstructPath(const int destinationCity)  {
    if (previousCity[destinationCity] != UNDEFINED) {
        reconstructPath(previousCity[destinationCity]);
        Path::getPathById(pathToPreviousCity[destinationCity])->getInfo();
    }

    cout << "\tGrad: ";
    City::getCityById(destinationCity)->getInfo();
    cout << endl;
}

const int PathSolver::findAdequatePath(City *curCity, const int destination) {
    int adequatePath = UNDEFINED;

    vector<int> paths = curCity->getConnections()[destination];

    for (auto &id : paths) {
        Path *path = Path::getPathById(id);

        if (path->getPathDisabled())
            continue;

        bool notFiltered = false;

        if (includedPathTypes.empty())
            notFiltered = true;
        else
            for (const Path::Type &type : includedPathTypes)
                if (type == path->getType()) {
                    notFiltered = true;
                    break;
                }

        if (!notFiltered)
            continue;

        if (adequatePath == UNDEFINED || path->getDistance() < Path::getPathById(adequatePath)->getDistance())
            adequatePath = path->getId();
    }

    return adequatePath;
}

const bool PathSolver::isCityReachable(const int destination) {
    return startingCity == destination || distances[destination] != INFINITE;
}

unordered_map<int, int> PathSolver::getPreviousCity() {
    return previousCity;
}

unordered_map<int, int> PathSolver::getPathToPreviousCity() {
    return pathToPreviousCity;
}

unordered_map<int, double> PathSolver::getDistances() {
    return distances;
}

