#include "raylib.h"
#include "entt/entt.hpp"

void CreateEntities(entt::registry &registry)
{
    auto e1 = registry.create();
    registry.emplace<Rectangle>(e1, Rectangle{0, 0, 100, 100});
    registry.emplace<Color>(e1, BLACK);

    auto e2 = registry.create();
    registry.emplace<Rectangle>(e2, Rectangle{400, 300, 50, 50});
    registry.emplace<Color>(e2, RED);

    auto e3 = registry.create();
    registry.emplace<Rectangle>(e3, Rectangle{600, 100, 70, 70});
    registry.emplace<Color>(e3, BLUE);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "ECS Test");
    SetTargetFPS(60);

    entt::registry registry;

    CreateEntities(registry);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        auto view = registry.view<Rectangle, Color>();
        for (auto entity : view)
        {
            auto &rect = view.get<Rectangle>(entity);
            auto &color = view.get<Color>(entity);
            DrawRectangleRec(rect, color);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}