#include "raylib.h"

// Structs
struct Player
{
    Vector2 position;
    float size;
    Color color;

    void Draw()
    {
        DrawRectangle((int)position.x, (int)position.y, (int)size, (int)size, color);
    }
};

struct Thorn
{
    Vector2 position;
    float size;
    Color color;

    void Draw()
    {
        DrawRectangle((int)position.x, (int)position.y, (int)size, (int)size, color);
    }
};

// Helper functions
int getCenter(int screenWidth, int rectWidth)
{
    return (screenWidth / 2) - (rectWidth / 2);
}
bool CheckCollision(Player plr, Thorn thr)
{
    return (
        plr.position.x < thr.position.x + thr.size &&
        plr.position.x + plr.size > thr.position.x &&
        plr.position.y < thr.position.y + thr.size &&
        plr.position.y + plr.size > thr.position.y);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "The Jump");

    // Initialize here
    float playerSize = 50.0f;
    Player player = {
        .position = {(float)getCenter(screenWidth, (int)playerSize), (float)screenHeight - 150},
        .size = playerSize,
        .color = WHITE,
    };
    float thornSize = 30.0f;
    Thorn thorn = {
        .position = {(float)getCenter(screenWidth, (int)thornSize) + 200, (float)screenHeight - 130},
        .size = thornSize,
        .color = WHITE,
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        // Draw background here
        DrawLine(0, screenHeight - 100, screenWidth, screenHeight - 100, WHITE);

        // Draw objects here
        // Jump
        if (IsKeyPressed(KEY_SPACE))
        {
            player.position.y -= 200;
        }

        // Go left and right
        if (IsKeyDown(KEY_A))
        {
            player.position.x -= 5;
        }
        if (IsKeyDown(KEY_D))
        {
            player.position.x += 5;
        }

        // Apply gravity
        if (player.position.y < screenHeight - 150)
        {
            player.position.y += 3;
        }

        // Collision
        if (CheckCollision(player, thorn))
        {
            CloseWindow();
            return 0;
        }

        player.Draw();
        thorn.Draw();

        // Text draw here
        DrawFPS(0, 0);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}