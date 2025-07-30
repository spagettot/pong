#ifndef MAIN_H
#define MAIN_H

#include "raylib.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    Rectangle rec;
    Color color;
    float speed;
    int score;
} Player;

typedef struct
{
    int x;
    int y;
    float radius;
    float speed_x;
    float speed_y;
    Color color;
} Ball;

typedef enum GameScreen { GAME, MENU, PAUSE } GameScreen;

void mouvement_and_colision(Ball *ball,  Player *Player1, Player *Player2);
void player_input_and_colision(Player *Player1, Player *Player2);

#endif
