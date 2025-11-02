#include<iostream>
#include "raylib.h"

using namespace std;

int main(){

    cout<< " Starting the game" << endl;
    const int screen_width = 1200;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "MINE PONG GAMEE");
    SetTargetFPS(60); // sets the frame per sec for the game and takes int as input;

    while(WindowShouldClose() == false) { // checks if the esc key is pressed || if the close icon is pressed
        BeginDrawing(); //starts by drawing the canvas;

        EndDrawing(); // ends the drawing the canvas;
    }

    CloseWindow();

    return 0;

}