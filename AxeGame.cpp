#include "raylib.h"
int main()
{
    int width{350};
    int height{200};
    InitWindow(width, height, "Steve");
    int circle_x{175};
    int circle_y{100};
    int radius{30};
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawCircle(circle_x, circle_y, radius, RED);

        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x += 10;
        }
        if (IsKeyDown(KEY_A) &&circle_x > 0)
            {
                circle_x -= 10;
            }

        EndDrawing();
    }
}
