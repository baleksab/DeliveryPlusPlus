cmake_minimum_required(VERSION 3.26)
project(Delivery__)

set(CMAKE_CXX_STANDARD 17)

add_executable(Delivery__
        src/Main.cpp
        src/node/City.cpp
        src/node/City.h
        src/node/Country.cpp
        src/node/Country.h
        src/exception/CountryDoesNotExist.h
        src/enums/Continent.h
        src/enums/Continent.cpp
        src/enums/Path.cpp
        src/enums/Path.h
        src/node/Connection.cpp
        src/node/Connection.h
)
