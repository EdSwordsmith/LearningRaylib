cmake_minimum_required(VERSION 3.17)
project(learningraylib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

find_package(raylib 3.0 QUIET)

if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/master.tar.gz)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(raylib)
endif()

add_subdirectory(external/entt)

add_executable(starfield starfield/main.cpp)
target_link_libraries(starfield raylib)

add_executable(ecs_test ecs_test/main.cpp)
target_link_libraries(ecs_test raylib EnTT)

add_executable(pong pong/main.c pong/player.c pong/player.h pong/ball.c pong/ball.h pong/ai.c pong/ai.h pong/structs.h)
target_link_libraries(pong raylib)