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
    int score;
} Player;

typedef struct
{
    Vector2 Pos;
    float radius;
    Color color;
} Ball;

void mouvement_and_colision(Ball *ball,  Player *Player1, Player *Player2);
void player_input_and_colision(Player *Player1, Player *Player2);
void pause();
void menu();

#endif
