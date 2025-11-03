#include<iostream>
#include "raylib.h"

using namespace std;

// Global  Variables;
const int screen_width = 1200;
const int screen_height = 800;

// Ball class;
class PongBall{
    public:
    float x, y;
    int speed_x;
    int speed_y;
    int radius;

    PongBall(float x_axis, float y_axis, int sp_x_axis, int sp_y_axis, int r){
        radius = 20;
        x = screen_width /2;
        y = screen_height /2;

        speed_x = 10;
        speed_y = 10;
    }
    PongBall(){
        radius = 20;
        x = screen_width /2;
        y = screen_height /2;

        speed_x = 10;
        speed_y = 10;
    }


    void DrawPongBall(){
        DrawCircle( x, y, 29, RED);
    }
    void update(){
        x += speed_x;
        y += speed_y;

        if(y + radius >= GetScreenHeight() || y - radius <= 0) speed_y *= -1;

        if(x + radius >= GetScreenWidth() || x - radius <= 0) speed_x *= -1;
    }
};

 // the rectangle thingy code;
class Paddle{
    public:
    float x, y, width, height;
    int speed;

    Paddle( float w, float h, int s) : width(w), height(h), speed(s) 
    {
        x = screen_width - width - 10;
        y = screen_height / 2 - height / 2;
    }
    void Drawing(){
        DrawRectangle( x, y, width, height, BLUE);
    }
};

// Global Objects;
PongBall Ball;
Paddle player(25, 120, 6);


// Main body of the program;

int main(){

    cout<< " Starting the game" << endl;
    InitWindow(screen_width, screen_height, "MINE PONG GAMEE");
    SetTargetFPS(60); // sets the frame per sec for the game and takes int as input;

    while(WindowShouldClose() == false) 
    { // checks if the esc key is pressed || if the close icon is pressed

        BeginDrawing(); //starts by drawing the canvas;

        Ball.update();

        //Erasing the canvas
        ClearBackground(BLACK); //this is erasing the previous screen
        // which is why the ball movement felt good 

        //Division of the canvas;
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, PURPLE);
        // drawing the ball;
        Ball.DrawPongBall();

        // Drawing the paddles or the slides;
        DrawRectangle(10, screen_height/2 - 60, 25, 120, BLUE);
        player.Drawing();

        EndDrawing(); // ends the drawing the canvas;
    }

    CloseWindow();

    return 0;

}