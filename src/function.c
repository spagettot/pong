#include "main.h"

static void Ball_physics(Ball *ball,  Player *Player1, Player *Player2)
{
    ball->x += ball->speed_x;
    ball->y += ball->speed_y;

    if (ball->y + ball->radius >= GetScreenHeight() || ball->y - ball->radius <= 0)
    {
        ball->speed_y *= -1;
    }

    if (ball->x + ball->radius >= GetScreenWidth())
    {
        ball->x = GetScreenWidth()/2;
        ball->y = GetScreenHeight()/2;

        Player1->score += 1;
	    ball->speed_x *= -1;
    }

    if (ball->x - ball->radius <= 0)
    {
        ball->x = GetScreenWidth()/2;
        ball->y = GetScreenHeight()/2;

        Player2->score += 1;

	    ball->speed_x *= -1;
    }

    if (CheckCollisionCircleRec((Vector2){ ball->x, ball->y }, ball->radius, Player1->rec) && ball->speed_x < 0) {
        ball->x = Player1->rec.x + Player1->rec.width + ball->radius;
        ball->speed_x *= -1;
    }

    if (CheckCollisionCircleRec((Vector2){ ball->x, ball->y }, ball->radius, Player2->rec) && ball->speed_x > 0) {
        ball->x = Player2->rec.x - ball->radius;
        ball->speed_x *= -1;
    }

}

void player_input_and_colision(Player *Player1, Player *Player2)
{
    if (IsKeyDown(KEY_S))
        Player1->rec.y = Player1->rec.y + Player1->speed;
    
    if (IsKeyDown(KEY_W))
        Player1->rec.y = Player1->rec.y - Player1->speed;

    if (IsKeyDown(KEY_K))
        Player2->rec.y = Player2->rec.y + Player2->speed;

    if (IsKeyDown(KEY_I))
        Player2->rec.y = Player2->rec.y - Player2->speed;
    
    if (Player1->rec.y < 0)
        Player1->rec.y = 0;
    if (Player1->rec.y + Player1->rec.height > GetScreenHeight())
        Player1->rec.y = GetScreenHeight() - Player1->rec.height;

    if (Player2->rec.y < 0)
        Player2->rec.y = 0;
    if (Player2->rec.y + Player1->rec.height > GetScreenHeight())
        Player2->rec.y = GetScreenHeight() - Player1->rec.height;
}

void mouvement_and_colision(Ball *ball,  Player *Player1, Player *Player2)
{
    Ball_physics(ball, Player1, Player2);
    player_input_and_colision(Player1, Player2);
}
