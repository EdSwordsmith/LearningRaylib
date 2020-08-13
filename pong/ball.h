#ifndef RAYLIBFUN_BALL_H
#define RAYLIBFUN_BALL_H

#include "structs.h"

void InitBall(Ball *ball);
void UpdateBall(Ball *ball, const float dt, Player *player, AI *ai);

#endif //RAYLIBFUN_BALL_H
