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
    int axe_length{50};

    int direction{10};

    int l_circle_x{circle_x - radius};
    int r_circle_x{circle_x + radius};
    int u_circle_y{circle_y - radius};
    int b_circle_y{circle_y + radius};

    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_length};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_length};

    bool collision_with_axe = (b_axe_y >= u_circle_y) &&
                              (u_axe_y <= b_circle_y) &&
                              (r_axe_x >= l_circle_x) &&
                              (l_axe_x <= r_circle_x);
    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(BLUE);

        if (collision_with_axe)
        {
            DrawText("Game Over", 400, 200, 20, RED);
        }
        else
        {
            // update the edges
            l_circle_x = circle_x - radius;
            r_circle_x = circle_x + radius;
            u_circle_y = circle_y - radius;
            b_circle_y = circle_y + radius;
            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_length;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;
            // update collision_with_axe
            collision_with_axe =
                (b_axe_y >= u_circle_y) &&
                (u_axe_y <= b_circle_y) &&
                (r_axe_x >= l_circle_x) &&
                (l_axe_x <= r_circle_x);
            DrawCircle(circle_x, circle_y, radius, RED);
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
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
        }
        EndDrawing();
    }
}
