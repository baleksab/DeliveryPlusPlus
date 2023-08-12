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
#include <vector>

using namespace std;

class PathSolver {
public:
    PathSolver(const int);

    void getPathTo(const int, const Path::Type type);
    void getBestPathTo(const int);
private:
    const int startingCity;

    unordered_map<int, unordered_map<int, double>> allDistances;
    unordered_map<int, unordered_map<int, int>> allPreviousCity;
    unordered_map<int, unordered_map<int, Path *>> allPreviousPath;

    void dijkstra(const int);
    const int findMinimum(unordered_map<int, double>, unordered_map<int, bool>);
    const bool isSmaller(const double, const double);
    Path * findAdequatePath(City *, const int, const int);
    void reconstructPath(const int, const int);
    const bool isCityReachable(const int, const int);
};


#endif //DELIVERY___PATHSOLVER_H
