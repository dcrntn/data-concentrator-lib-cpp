cmake_minimum_required(VERSION "3.16.3")

project("DataConcentrator")
include(FetchContent)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

add_executable("dconcMain" "main.cpp")
target_link_directories("dconcMain" PRIVATE ${CMAKE_SOURCE_DIR}/../build/)
target_link_libraries("dconcMain" PRIVATE "dconc")
target_link_libraries("dconcMain" PRIVATE "nlohmann_json::nlohmann_json")