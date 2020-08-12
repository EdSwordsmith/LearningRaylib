#include "raylib.h"
#include "entt/entt.hpp"

using Velocity = Vector2;

void CreateEntities(entt::registry &registry)
{
    auto e1 = registry.create();
    registry.emplace<Rectangle>(e1, Rectangle{0, 0, 100, 100});
    registry.emplace<Color>(e1, BLACK);

    auto e2 = registry.create();
    registry.emplace<Rectangle>(e2, Rectangle{400, 300, 50, 50});
    registry.emplace<Velocity>(e2, Velocity{200, 0});
    registry.emplace<Color>(e2, RED);

    auto e3 = registry.create();
    registry.emplace<Rectangle>(e3, Rectangle{600, 100, 70, 70});
    registry.emplace<Velocity>(e3, Velocity{0, 100});
    registry.emplace<Color>(e3, BLUE);
}

void MovementSystem(entt::registry &registry, float dt)
{
    auto view = registry.view<Rectangle, Velocity>();

    for (auto entity : view)
    {
        auto &vel = view.get<Velocity>(entity);
        auto &rect = view.get<Rectangle>(entity);

        rect.x += vel.x * dt;
        rect.y += vel.y * dt;

        auto width = GetScreenWidth();
        auto height = GetScreenHeight();

        if (rect.x < -rect.width) rect.x = width - rect.width;
        else if (rect.x > width) rect.x = 0;

        if (rect.y < -rect.height) rect.y = height - rect.height;
        else if (rect.y > height) rect.y = 0;
    }
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
        float dt = GetFrameTime();
        MovementSystem(registry, dt);

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