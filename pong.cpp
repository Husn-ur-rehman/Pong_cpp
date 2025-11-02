#include<iostream>
#include "raylib.h"

using namespace std;

class PongBall{
    public:
    float x, y;
    int speed_x;
    int speed_y;
    int radius;

    void DrawPongBall(){
        DrawCircle( x, y, 29, RED);
    }
    void update(){
        x += speed_x;
        y += speed_y;
    }
};

PongBall Ball;


int main(){

    cout<< " Starting the game" << endl;
    const int screen_width = 1200;
    const int screen_height = 800;
    InitWindow(screen_width, screen_height, "MINE PONG GAMEE");
    SetTargetFPS(60); // sets the frame per sec for the game and takes int as input;

    Ball.radius = 20;
    Ball.x = screen_width /2;
    Ball.y = screen_height /2;

    Ball.speed_x = 10;
    Ball.speed_y = 10;

    


    while(WindowShouldClose() == false) { // checks if the esc key is pressed || if the close icon is pressed
        BeginDrawing(); //starts by drawing the canvas;

        //Division of the canvas;
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, PURPLE);
        // drawing the ball;
        Ball.DrawPongBall();

        // Drawing the paddles or the slides;
        DrawRectangle(10, screen_height/2 - 60, 25, 120, BLUE);
        DrawRectangle(screen_width - 35, screen_height/2 - 60, 25, 120, BLUE);



        EndDrawing(); // ends the drawing the canvas;
    }

    CloseWindow();

    return 0;

}