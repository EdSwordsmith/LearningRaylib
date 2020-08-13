#ifndef RAYLIBFUN_AI_H
#define RAYLIBFUN_AI_H

#include "structs.h"

void InitAI(AI *ai);
void UpdateAI(AI *ai, const float dt, const Ball *ball);

#endif //RAYLIBFUN_AI_H
