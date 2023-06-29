cmake_minimum_required(VERSION 3.25)
project(DeliveryPlusPlus CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(DeliveryPlusPlus
        "Main.cpp"
        "Header Files/Continent.h" "Source Files/Continent.cpp" "Header Files/Country.h" "Source Files/Country.cpp")
