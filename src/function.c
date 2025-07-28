#include "main.h"

float speed_x = 5;
float speed_y = 5;
float Player1_speed = 8;
float Player2_speed = 8;

void Ball_physics(Ball *ball,  Player *Player1, Player *Player2)
{
    ball->Pos.x += speed_x;
    ball->Pos.y += speed_y;

    if (ball->Pos.y + ball->radius >= GetScreenHeight() || ball->Pos.y - ball->radius <= 0)
    {
        speed_y *= -1;
    }

    if (ball->Pos.x + ball->radius >= GetScreenWidth())
    {
        ball->Pos.x = GetScreenWidth()/2;
        ball->Pos.y = GetScreenHeight()/2;

        Player1->score += 1;
    }

    if (ball->Pos.x - ball->radius <= 0)
    {
        ball->Pos.x = GetScreenWidth()/2;
        ball->Pos.y = GetScreenHeight()/2;

        Player2->score += 1;
    }

    if (CheckCollisionCircleRec(ball->Pos, ball->radius, Player1->rec) || CheckCollisionCircleRec(ball->Pos, ball->radius, Player2->rec))
    {
        speed_x *= -1;
    }
}

void player_input_and_colision(Player *Player1, Player *Player2)
{
    if (IsKeyDown(KEY_S))
        Player1->rec.y = Player1->rec.y + Player1_speed;
    
    if (IsKeyDown(KEY_W))
        Player1->rec.y = Player1->rec.y - Player1_speed;

    if (IsKeyDown(KEY_K))
        Player2->rec.y = Player2->rec.y + Player2_speed;

    if (IsKeyDown(KEY_I))
        Player2->rec.y = Player2->rec.y - Player2_speed;
    
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

void menu()
{
    Texture2D img = LoadTexture("res/menus/menu.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            DrawTexture(img, 0, 0, WHITE);
        EndDrawing();

        if (IsKeyPressed(KEY_ENTER)) break;
    }

    UnloadTexture(img);
}

void pause()
{
    Texture2D img = LoadTexture("res/menus/pause.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            DrawTexture(img, 0, 0, WHITE);
        EndDrawing();

        if (IsKeyPressed(KEY_ESCAPE)) break;
    }

    UnloadTexture(img);
}