cmake_minimum_required(VERSION 3.26)
project(Delivery__)

set(CMAKE_CXX_STANDARD 17)

add_executable(Delivery__
        src/Main.cpp
        src/exception/CountryDoesNotExist.h
        src/interface/Entity.h
        src/location/City.cpp
        src/location/City.h
        src/location/Country.cpp
        src/location/Country.h
        src/exception/CityDoesNotExist.h
        src/location/Path.cpp
        src/location/Path.h
        src/exception/SameCityNotAllowed.h
        src/location/PathSolver.cpp
        src/location/PathSolver.h
        src/interface/Entity.cpp
)
