//
// Created by C425 on 10/08/2023.
//

#ifndef DELIVERY___PATHSOLVER_H
#define DELIVERY___PATHSOLVER_H

#define INFINITE -1
#define UNDEFINED -2

#define ALL_PATH_TYPES -1

#include "../exception/UnexpectedBehaviour.h"
#include "City.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class PathSolver {
public:
    PathSolver(const int, const unordered_set<Path::Type>);

    void getPathTo(const int);
    const bool isCityReachable(const int);
private:
    const int startingCity;
    const unordered_set<Path::Type> includedPathTypes;

    unordered_map<int, bool> visitedCity;
    unordered_map<int, double> distances;
    unordered_map<int, int> previousCity;
    unordered_map<int, Path *> pathToCity;

    const int findMinimum();
    const bool isSmaller(const double, const double);
    Path * findAdequatePath(City *, const int);
    void reconstructPath(const int);
};


#endif //DELIVERY___PATHSOLVER_H
