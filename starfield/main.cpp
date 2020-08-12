#include "raylib.h"

#define WIDTH 800
#define HEIGHT 800

#define STARS 200

struct Star
{
    Vector3 pos;

    Star()
    {
        pos.x = GetRandomValue(-WIDTH / 2, WIDTH / 2);
        pos.y = GetRandomValue(-HEIGHT / 2, HEIGHT / 2);
        pos.z = GetRandomValue(0, WIDTH);
    }

    void Update()
    {
        pos.z -= 5;
        if (pos.z < 1)
            pos.z = WIDTH;
    }
};

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Starfield");

    SetTargetFPS(60);

    Camera3D camera = { 0 };
    camera.position = Vector3{0.0f, 0.0f, 0.0f};
    camera.target = (Vector3){ 0.0f, 0.0f, 2*WIDTH};
    camera.up = Vector3{ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.type = CAMERA_PERSPECTIVE;

    Star stars[STARS];

    while (!WindowShouldClose())
    {
        for (int i = 0; i < STARS; i++)
        {
            stars[i].Update();
        }

        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera);

        for (int i = 0; i < STARS; i++)
        {
            DrawSphere(stars[i].pos, 2, WHITE);
        }

        EndMode3D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
