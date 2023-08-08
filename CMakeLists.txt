cmake_minimum_required(VERSION 3.26)
project(Delivery__)

set(CMAKE_CXX_STANDARD 17)

add_executable(Delivery__
        src/Main.cpp
        src/location/City.cpp
        src/location/City.h
        src/location/Country.cpp
        src/location/Country.h
        src/exception/CountryDoesNotExist.h
        src/interfaces/IDescriptive.h
        src/location/Connection.cpp
        src/location/Connection.h
        src/location/Path.cpp
        src/location/Path.h
)
