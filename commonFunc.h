#ifndef COMMONFUNC_H_INCLUDED
#define COMMONFUNC_H_INCLUDED

#include "include.h"

//#define TILE_SIZE 64
#define BLANK_TILE 0

#define num_frame 8

#define GRAVITY_SPEED 3
#define MAX_FALL_SPEED 12

#define PLAYER_SPEED 10
#define PLAYER_HIGHT_VAL 30;

//Screen
const int FPS = 20;
const int frameDelay = 1000/FPS;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;

const int maxX = 10;
const int maxY = 20;

const int TILE_SIZE = SCREEN_HEIGHT/maxX;

const int start_y = TILE_SIZE*8;

const int RENDER_DRAW_COLOR = 0XFF;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;


const double speed_weapon = 10;
const double angle = 45;


typedef struct Input
{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
    int shoot_;
} Input;

namespace Collision
{
    bool checkCollision(const SDL_Rect& object1, const SDL_Rect& object2);
}


#endif // COMMONFUNC_H_INCLUDED
