#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "raylib.h"

int select_color(const char letter);

int main (void) 
{
    unsigned int y;
    unsigned int x;
    char *title = "Pi";
    char *pi_decimals = (char *) (malloc(sizeof(char) * 3600));
    struct Color color[] = 
    {
        {25,255,25,100},
        {50,225,50,100},
        {75,200,75,100},
        {100,175,100,100},
        {125,150,125,100},
        {150,125,150,100},
        {175,100,175,100},
        {200,75,200,100},
        {225,50,225,100},
        {255,25,255,100}
    };
    InitWindow(800, 450, title);
    SetTargetFPS(60);
    
    FILE *file = fopen("pi.txt", "r");
    if (file == NULL)
        SetWindowTitle("No se puede acceder al archivo de los decimales de pi");
    else 
    {
        *pi_decimals = fscanf(file, "%s", pi_decimals);
    }
    
    while (!WindowShouldClose())
    {
        // update vars
        y = 10;
        x = 10;
        // draw
        BeginDrawing();
        for (;y != 450; y += 10)
            DrawLine(0, y, 800, y, BLACK);
        for (; x != 800; x += 10)
            DrawLine(x, 0, x, 450, BLACK);
        ClearBackground(WHITE);
        
        int counter = 0;
        for (size_t i = 0; i < 80; ++i)
        {
            for (size_t j = 0; j < 45; ++j)
            {
                if (i == 0 && j == 0) DrawRectangle(i , j, 10, 10, color[1]);
                else DrawRectangle(i * 10, j * 10, 10, 10, color[select_color(pi_decimals[counter])]);
                ++counter;
            }
        }
        EndDrawing();   
    }
    CloseWindow();
    return 0;
}

int select_color(const char letter)
{
    switch (letter) 
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
    }
    return -1;
}