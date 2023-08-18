cmake_minimum_required(VERSION 3.10)
project(DeliveryPlusPlus)

set(CMAKE_CXX_STANDARD 14)

add_executable(DeliveryPlusPlus
        src/Main.cpp
        src/entity/Entity.h
        src/location/City.cpp
        src/location/City.h
        src/location/Country.cpp
        src/location/Country.h
        src/location/Path.cpp
        src/location/Path.h
        src/location/PathSolver.cpp
        src/location/PathSolver.h
        src/entity/Entity.cpp
        src/package/Package.cpp
        src/package/Package.h
        src/vehicle/Vehicle.cpp
        src/vehicle/Vehicle.h
        src/vehicle/types/Van.h
        src/vehicle/types/Truck.h
        src/vehicle/types/Airplane.h
        src/vehicle/types/Ship.h
        src/exception/UnexpectedBehaviour.h
        src/vehicle/types/Train.h
)
