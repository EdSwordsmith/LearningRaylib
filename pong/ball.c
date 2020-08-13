#include "ball.h"

void InitBall(Ball *ball)
{
    ball->rect.x = GetScreenWidth() / 2.0f;
    ball->rect.y = GetScreenHeight() / 2.0f;
    ball->rect.width = 20;
    ball->rect.height = 20;
    ball->speed = 200;
    ball->vel.x = -ball->speed;
    ball->vel.y = 0;
}

void UpdateBall(Ball *ball, const float dt, Player *player, AI *ai)
{
    ball->rect.x += ball->vel.x * dt;
    ball->rect.y += ball->vel.y * dt;

    if (CheckCollisionRecs(ball->rect, player->rect))
    {
        ball->vel.x = ball->speed;
        float middleBall = ball->rect.y + ball->rect.height / 2;
        float middlePlayer = player->rect.y + player->rect.height / 2;
        float collisionPoint = middleBall - middlePlayer;
        ball->vel.y = collisionPoint * 5;
    }

    if (CheckCollisionRecs(ball->rect, ai->rect))
    {
        ball->vel.x = -ball->speed;
        float middleBall = ball->rect.y + ball->rect.height / 2;
        float middleAI = ai->rect.y + ai->rect.height / 2;
        float collisionPoint = middleBall - middleAI;
        ball->vel.y = collisionPoint * 5;
    }

    if (ball->rect.y < 0)
    {
        ball->rect.y = 0;
        ball->vel.y = -ball->vel.y;
    }
    else if (ball->rect.y + ball->rect.height > GetScreenHeight())
    {
        ball->rect.y = GetScreenHeight() - ball->rect.height;
        ball->vel.y = -ball->vel.y;
    }

    if (ball->rect.x < -ball->rect.width)
    {
        ball->rect.x = GetScreenWidth() / 2.0f - ball->rect.width / 2.0f;
        ball->rect.y = GetScreenHeight() / 2.0f - ball->rect.height / 2.0f;
        ball->vel.x = ball->speed;
        ai->score++;
    }
    else if (ball->rect.x > GetScreenWidth())
    {
        ball->rect.x = GetScreenWidth() / 2.0f - ball->rect.width / 2.0f;
        ball->rect.y = GetScreenHeight() / 2.0f - ball->rect.height / 2.0f;
        ball->vel.x = -ball->speed;
        player->score++;
    }
}
