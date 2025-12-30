#include "raylib.h"

int getCenter(int screenWidth, int rectWidth)
{
    return (screenWidth / 2) - (rectWidth / 2);
}

struct Player
{
    Vector2 position;
    float size;
    Color color;

    void Draw()
    {
        DrawRectangle(position.x, position.y, size, size, color);
    }
};

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

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        // Draw background here
        DrawLine(0, screenHeight - 100, screenWidth, screenHeight - 100, WHITE);

        // Draw objects here
        player.Draw();

        // Text draw here
        DrawFPS(0, 0);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}