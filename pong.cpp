#include<iostream>
#include "raylib.h"

using namespace std;

// Global  Variables;

Color Green = Color{38, 185, 154, 255}; // 255 for transparent the args for color is {green,red, blue,transparent}
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

const int screen_width = 1200;
const int screen_height = 800;
int player_score = 0;
int AI_score = 0;

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
        radius = 10;
        x = screen_width /2;
        y = screen_height /2;

        speed_x = 10;
        speed_y = 10;
    }


    void DrawPongBall(){
        DrawCircle( x, y, 20, Yellow);
    }
    void update(){
        x += speed_x;
        y += speed_y;

        if(y + radius >= GetScreenHeight() || y - radius <= 0) speed_y *= -1;

        if(x + radius >= GetScreenWidth()){
            AI_score++;
            ResetBall();
        } 

        if(x - radius <= 0) {
            player_score++;
            ResetBall();
        }
    
    }

    void ResetBall(){
    
        x = screen_width /2;
        y = screen_height /2;

        int sp_choice[2] = {-1,1};

        speed_x *= sp_choice[GetRandomValue(0,1)];
        speed_y *= sp_choice[GetRandomValue(0,1)];

    }


};

 // the rectangle thingy code;
class Paddle{
    protected:
    void Limit(){
        if( y <= 0) y = 0;

        if(y + height >= GetScreenHeight()) y = GetScreenHeight() - height;
    }
    public:
    float x, y, width, height;
    int speed;

    Paddle( float w, float h, int s) : width(w), height(h), speed(s) 
    {
        x = screen_width - width - 10;
        y = screen_height / 2 - height / 2;
    }
    Paddle(){

    }

    void Drawing(){
        DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, BLUE); // args (rectangle, roundness, segment, color)
    }

    void update(){
        if(IsKeyDown(KEY_UP)) y = y - speed;

        if( IsKeyDown(KEY_DOWN)) y = y + speed; 

        Limit();
    }
};

// Opponent class

class AIPaddle: public Paddle{
    public:
    AIPaddle(float w, float h, int s){
        width = w;
        height = h;
        speed = s;
        x = 10;
        y = screen_height/2 - height/2; 

    }

    void update(int pongball_y){

        if( y + height/ 2 > pongball_y) y = y - speed;
        if( y + height/2 <= pongball_y) y = y + speed;

        Limit();
    }


};


// Global Objects;
PongBall Ball;
Paddle player(25, 120, 6);
AIPaddle AI(25, 120, 6);

// Main body of the program;

int main(){

    cout<< " Starting the game" << endl;
    InitWindow(screen_width, screen_height, "MINE PONG GAMEE");
    SetTargetFPS(60); // sets the frame per sec for the game and takes int as input;

    while(WindowShouldClose() == false) 
    { // checks if the esc key is pressed || if the close icon is pressed

        BeginDrawing(); //starts by drawing the canvas;

        //Updating game objects;
        Ball.update();
        player.update();
        AI.update(Ball.y);

        //Collision checking
        if(CheckCollisionCircleRec(Vector2{Ball.x, Ball.y}, Ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
        Ball.speed_x *= -1;
        
        if(CheckCollisionCircleRec(Vector2{Ball.x, Ball.y}, Ball.radius, Rectangle{AI.x, AI.y, AI.width, AI.height}))
        Ball.speed_x *= -1;


        //Erasing the canvas
        ClearBackground(Green); //this is erasing the previous screen
        // which is why the ball movement felt good 
        DrawRectangle(screen_width/2, 0, screen_width/2, screen_height/2, Green);
        DrawCircle(screen_width/2, screen_height/2, 150, Light_Green);
        //Division of the canvas;
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);

        // drawing the ball;
        Ball.DrawPongBall();

        // Drawing the paddles or the slides;
        AI.Drawing();
        player.Drawing();
        // To show text on the screen the args are (jo likhhna hai, x,y co ordinates, size text ka, and lastly color);
        DrawText(TextFormat("%i", AI_score), screen_width/4, 10, 50, Yellow);
        DrawText(TextFormat("%i", player_score), 3*screen_width/4, 10, 50, Yellow);

        EndDrawing(); // ends the drawing the canvas;
    }

    CloseWindow();

    return 0;

}