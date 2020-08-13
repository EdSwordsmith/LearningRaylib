#include "player.h"

void InitPlayer(Player *player) 
{
    player->rect.x = 50;
    player->rect.y = GetScreenHeight() / 2.0f;
    player->rect.width = 20;
    player->rect.height = 100;
    player->speed = 500;
    player->score = 0;
}

void UpdatePlayer(Player *player, const float dt)
{
    if (IsKeyDown(KEY_W))
        player->rect.y -= player->speed * dt;
    else if (IsKeyDown(KEY_S))
        player->rect.y += player->speed * dt;

    if (player->rect.y < 0)
        player->rect.y = 0;
    else if (player->rect.y + player->rect.height > GetScreenHeight())
        player->rect.y = GetScreenHeight() - player->rect.height;
}
