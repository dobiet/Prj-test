#include "include.h"
#include "commonFunc.h"
#include "Texture.h"
#include "Object.h"
#include "Game.h"
#include "Map.h"
#include "Timer.h"
Game *game = nullptr;

int main(int argv, char* args[])
{

    Timer fps;
    game = new Game();
    game->init("Ban sung", SCREEN_WIDTH, SCREEN_HEIGHT);

    while(game->running()){

        game->handleEvents();
        game->update();
        game->render();

        int imp_time = fps.get_ticks();
        if(imp_time < frameDelay)
        {
            SDL_Delay(frameDelay - imp_time);
        }
    }

    game->clean();

    return 0;
}
