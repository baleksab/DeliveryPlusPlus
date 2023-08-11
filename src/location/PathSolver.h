//
// Created by C425 on 10/08/2023.
//

#ifndef DELIVERY___PATHSOLVER_H
#define DELIVERY___PATHSOLVER_H

#define INFINITE -1
#define UNDEFINED -2

#include "../exception/CityNotReachable.h"
#include "City.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class PathSolver {
public:
    PathSolver(const int, const Path::Type);

    void getPathTo(const int);
private:
    const int startingCity;
    const Path::Type type;

    unordered_map<int, double> distances;
    unordered_map<int, int> previousCity;
    unordered_map<int, Path *> previousPath;

    const int findMinimum(unordered_map<int, bool>);
    const bool isSmaller(const double, const double);
    Path * findAdequatePath(City *, const int);
    void reconstructPath(const int);
    const bool isCityReachable(const int);
};


#endif //DELIVERY___PATHSOLVER_H
