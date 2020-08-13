#include "ai.h"

void InitAI(AI *ai)
{
    ai->rect.width = 20;
    ai->rect.height = 100;
    ai->rect.x = GetScreenWidth() - ai->rect.width - 50;
    ai->rect.y = GetScreenHeight() / 2.0f;
    ai->speed = 500;
    ai->vel = 0;
    ai->timer = 0;
    ai->rate = 0.5;
    ai->score = 0;
}

void UpdateAI(AI *ai, const float dt, const Ball *ball) 
{
    ai->rect.y += ai->vel * dt;

    if (ai->rect.y < 0)
        ai->rect.y = 0;
    else if (ai->rect.y + ai->rect.height > GetScreenHeight())
        ai->rect.y = GetScreenHeight() - ai->rect.height;

    ai->timer += dt;

    if (ai->timer > ai->rate)
    {
        ai->timer = 0;
        if (ball->rect.y + ball->rect.height < ai->rect.y)
            ai->vel = -ai->speed;
        else if (ball->rect.y > ai->rect.y + ai->rect.height)
            ai->vel = ai->speed;
        else
            ai->vel = 0;
    }
}
