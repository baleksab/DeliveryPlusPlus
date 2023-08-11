//
// Created by C425 on 10/08/2023.
//

#ifndef DELIVERY___PATHSOLVER_H
#define DELIVERY___PATHSOLVER_H

#define INFINITE -1
#define UNDEFINED -2

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "City.h"

using namespace std;

class PathSolver {
public:
    PathSolver(const int, const Path::Type);

    void reconstructPath(const int destinationCity);
private:
    const int startingCity;
    const Path::Type type;

    unordered_map<int, double> distances;
    unordered_map<int, int> previousCity;

    const int findMinimum(unordered_map<int, bool>);
    const bool isSmaller(const double, const double);
    const Path * findAdequatePath(City *, const int);
};


#endif //DELIVERY___PATHSOLVER_H
