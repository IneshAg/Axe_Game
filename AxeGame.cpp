#include "raylib.h"
int main()
{
    int width{800};
    int height{400};
    InitWindow(width, height, "Steve");
    int circle_x{200};
    int circle_y{200};
    int radius{30};

    int axe_x{400};
    int axe_y{0};

    int direction{10};
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLUE);
        DrawCircle(circle_x, circle_y, radius, RED);
        DrawRectangle(axe_x, axe_y, 50, 50, RED);
        axe_y += direction;
        if (axe_y > height || axe_y < 0)

        {
            direction = -direction;
        }
        if (IsKeyDown(KEY_D) && circle_x < width)
        {
            circle_x += 10;
        }
        if (IsKeyDown(KEY_A) && circle_x > 0)
        {
            circle_x -= 10;
        }

        EndDrawing();
    }
}
