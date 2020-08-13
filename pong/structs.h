#ifndef RAYLIBFUN_STRUCTS_H
#define RAYLIBFUN_STRUCTS_H

#include "raylib.h"

typedef struct {
    Rectangle rect;
    float speed;
    int score;
} Player;

typedef struct {
    Rectangle rect;
    Vector2 vel;
    float speed;
} Ball;

typedef struct {
    Rectangle rect;
    float speed;
    float vel;
    float timer;
    float rate;
    int score;
} AI;

#endif //RAYLIBFUN_STRUCTS_H
