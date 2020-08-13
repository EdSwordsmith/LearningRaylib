#include "raylib.h"
#include "flecs.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Flecs Test");
    SetTargetFPS(60);

    ecs_world_t *world = ecs_init();
    ECS_COMPONENT(world, Rectangle);

    ecs_entity_t e = ecs_new(world, Rectangle);
    ecs_set(world, e, Rectangle, {10, 10, 100, 100});

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        ecs_query_t *query = ecs_query_new(world, "Rectangle");
        ecs_iter_t it = ecs_query_iter(query);

        while (ecs_query_next(&it))
        {
            Rectangle *rect = ecs_column(&it, Rectangle, 1);
            for (int i = 0; i < it.count; ++i) {
                DrawRectangleRec(rect[i], BLACK);
            }
        }

        EndDrawing();
    }

    CloseWindow();
    ecs_fini(world);

    return 0;
}
