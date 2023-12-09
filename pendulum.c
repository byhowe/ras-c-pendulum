#include <math.h>
#include <stdlib.h>
#include <raylib.h>

typedef struct {
    double radius;
    double angular_speed;
    double length;
    void *next;
} Circle;

int main(void)
{
    const int screen_w = 1000;
    const int screen_h = 1000;

    Circle circle0 = {.radius = .0, .angular_speed = .0, .length = .0};
    Circle circle1 = {.radius = 50.0, .angular_speed = 0.8, .length = 90.0};
    Circle circle2 = {.radius = 25.0, .angular_speed = 2.1, .length = 100.0};
    Circle circle3 = {.radius = 25.0, .angular_speed = 1.3, .length = 30.0};

    circle0.next = &circle1;
    circle1.next = &circle2;
    circle2.next = &circle3;
    circle3.next = NULL;

    InitWindow(screen_w, screen_h, "RAS Pendulum");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        double posx = (double)GetScreenWidth() / 2;
        double posy = (double)GetScreenHeight() / 2;
        double prev_posx;
        double prev_posy;
        double theta;

        const Circle* prev = &circle0;
        const Circle* current;

        while (prev->next) {
            current = prev->next;
            DrawCircle(posx, posy, current->radius, RED);

            theta = current->angular_speed * GetTime();
            prev_posx = posx;
            prev_posy = posy;
            posx += cos(theta) * current->length;
            posy += sin(theta) * current->length;

            DrawLine(prev_posx, prev_posy, posx, posy, BLACK);

            prev = current;
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
