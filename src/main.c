#include "main.h"

int fontSize = 40;

int height = 600;
int width = 800;

Player Player1 = { { 10, 250, 20, 100 }, BLUE, 0 };
Player Player2 = { { 770, 250, 20, 100 }, RED, 0 };
Ball ball = { { 400, 300 }, 5.0, ORANGE };

GameScreen state = MENU;

int main(void)
{
    InitWindow(width, height, "pong");
    SetExitKey(KEY_BACKSPACE);

    Image icon = LoadImage("res/icon/ping-pong.png");

    Texture2D PauseScreen = LoadTexture("res/menus/pause.png");
    Texture2D MenuScreen = LoadTexture("res/menus/menu.png");

    SetWindowIcon(icon);
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        if (state == MENU) {
            if (IsKeyPressed(KEY_ENTER)) {
                state = GAME;
            }
        }
        else if (state == GAME) {
            if (IsKeyPressed(KEY_ESCAPE)) {
                state = PAUSE;
            }

            mouvement_and_colision(&ball, &Player1, &Player2);
        }
        else if (state == PAUSE) {
            if (IsKeyPressed(KEY_ESCAPE)) {
                state = GAME;
            }
        }

        BeginDrawing();

            if (state == MENU) {
                DrawTexture(MenuScreen, 0, 0, WHITE);
            }

            else if (state == GAME)
            {
                ClearBackground(WHITE);

                DrawText(TextFormat("%d-%d", Player1.score, Player2.score), width/2-fontSize, 20, fontSize, BLACK);

                DrawRectangle(Player1.rec.x, Player1.rec.y, Player1.rec.width, Player1.rec.height, Player1.color);

                DrawRectangle(Player2.rec.x, Player2.rec.y, Player2.rec.width, Player2.rec.height, Player2.color);

                DrawCircle(ball.Pos.x, ball.Pos.y, ball.radius, ball.color);
            }

            else if (state == PAUSE)
            {
                DrawTexture(PauseScreen, 0, 0, WHITE);
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
