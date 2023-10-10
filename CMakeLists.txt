cmake_minimum_required(VERSION "3.16.3")
set(CMAKE_CXX_STANDARD 17)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
    GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

project("DataConcentrator")

add_library("dconc" "dconc.cpp")
target_link_libraries("dconc" PRIVATE cpr::cpr)
target_link_libraries("dconc" PRIVATE nlohmann_json::nlohmann_json)
