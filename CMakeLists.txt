cmake_minimum_required(VERSION 3.26)
project(TouhouSDK)
set(CMAKE_CXX_STANDARD 23)

# Paths
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake-modules)
set(SDL2_PATH "C:/Users/Legit/Documents/SDL2-2.28.5/x86_64-w64-mingw32")

# SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(TouhouSDK main.cpp
        "ScarletDevilKingdom/handler/SDL2_handler.cpp"
        "ScarletDevilKingdom/handler/runGame.cpp"
)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})