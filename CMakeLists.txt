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

add_executable(flecs_test flecs_test/main.c flecs_test/flecs.c flecs_test/flecs.h)
target_link_libraries(flecs_test raylib)

file(GLOB ASSETS appbundle_test/assets/*)
set_property(SOURCE "${ASSETS}"
        PROPERTY MACOSX_PACKAGE_LOCATION "Resources/assets")
add_executable(appbundle_test appbundle_test/main.c "${ASSETS}")
target_link_libraries(appbundle_test raylib)
set_target_properties(appbundle_test PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_FRAMEWORK_IDENTIFIER io.github.edswordsmith.bruh)
