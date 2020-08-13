#include "stdio.h"
#include "raylib.h"

#include "player.h"
#include "ball.h"
#include "ai.h"

int main(void)
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    Player player;
    InitPlayer(&player);

    Ball ball;
    InitBall(&ball);

    AI ai;
    InitAI(&ai);
    char scoreText[2][2];

    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();

        UpdatePlayer(&player, dt);
        UpdateBall(&ball, dt, &player, &ai);
        UpdateAI(&ai, dt, &ball);

        if (player.score == 10 || ai.score == 10)
        {
            player.score = 0;
            ai.score = 0;
        }

        sprintf(scoreText[0], "%d", player.score);
        sprintf(scoreText[1], "%d", ai.score);

        BeginDrawing();

        ClearBackground(BLACK);
        DrawRectangleRec(player.rect, WHITE);
        DrawRectangleRec(ball.rect, WHITE);
        DrawRectangleRec(ai.rect, WHITE);

        DrawText(scoreText[0], 150, 0, 100, WHITE);
        DrawText(scoreText[1], GetScreenWidth() - 200, 0, 100, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}