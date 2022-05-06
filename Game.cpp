#include "include.h"
#include "Object.h"
#include "Game.h"
#include "Map.h"
#include "Object.h"
#include "commonFunc.h"

Object* player1;
Object* player2;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char* title, int width, int height)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        isRunning = true;
    }

    player1 = new Object("img/fig.png", 4*TILE_SIZE, 5*TILE_SIZE);
    player2 = new Object("img/fig.png", 15*TILE_SIZE, 5*TILE_SIZE);

}

void Game::handleEvents()
{
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            isRunning = false;
            break;

        case SDL_KEYDOWN:
            switch( event.key.keysym.sym )
            {
                case SDLK_d:
                    player1->status  = 1;
                    player1->input_type_.right_ = 1;
                    player1->input_type_.left_ = 0;
                    break;

                case SDLK_a:
                    player1->status = 2;
                    player1->input_type_.left_ = 1;
                    player1->input_type_.right_ = 0;
                    break;

                case SDLK_w:
                    player1->input_type_.jump_= 1;
                    break;

                case SDLK_t:
                    player1->input_type_.shoot_=1;
                    break;

                case SDLK_RIGHT:
                    player2->status  = 1;
                    player2->input_type_.right_ = 1;
                    break;

                case SDLK_LEFT:
                    player2->status = 2;
                    player2->input_type_.left_ = 1;

                    break;

                case SDLK_UP:
                    player2->input_type_.jump_= 1;
                    break;

                case SDLK_m:
                    player2->input_type_.shoot_ = 1;
                    break;
            }
            break;
        case SDL_KEYUP:
            switch( event.key.keysym.sym )
            {
                case SDLK_d:
                    player1->input_type_.right_ = 0;
                    break;

                case SDLK_a:
                    player1->input_type_.left_ = 0;
                    break;

                case SDLK_w:
                    player1->input_type_.jump_ = 0;
                    break;

                case SDLK_t:
                    player1->input_type_.shoot_ = 0;

                case SDLK_RIGHT:
                    player2->input_type_.right_ = 0;
                    break;

                case SDLK_LEFT:
                    player2->input_type_.left_ = 0;
                    break;

                case SDLK_UP:
                    player2->input_type_.jump_ = 0;
                    break;

                case SDLK_m:
                    player2->input_type_.shoot_ = 0;

                break;
            }
            break;
        default:
            break;
    }
}

void Game::update()
{
    player1->updateObject();
    player2->updateObject();
}

void Game::render()
{
    SDL_RenderClear(renderer);

    Texture backgr;
    backgr.loadFromFile("img/backGround.jpg");
    backgr.setRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    backgr.renderTexture(NULL);
    Map game_map;
    game_map.loadMap("map/map.txt");
    game_map.drawMap();

    player1->doObject(game_map);
    player2->doObject(game_map);
    player1->handleWeapon();
    player2->handleWeapon();

    std::vector<Weapon*> weapon_list1 = player1->get_weapon_list();
    std::vector<Weapon*> weapon_list2 = player2->get_weapon_list();
    for(int i=0;i<weapon_list1.size();i++){
        Weapon* p_weapon = weapon_list1.at(i);
        if(p_weapon){
            /*SDL_Rect x = p_weapon->getRect();
            SDL_Rect y = player1->GetRectFrame();
            std::cout<<x.x<<" "<<x.y<<" "<<x.w<<" "<<x.h<<'\n';
            std::cout<<y.x<<" "<<y.y<<" "<<y.w<<" "<<y.h<<'\n';*/
            bool check = Collision::checkCollision(p_weapon->getRect(), player1->GetRectFrame());
            if( check ) player1->removeWeapon(i);
            bool check1 = Collision::checkCollision(p_weapon->getRect(), player2->GetRectFrame());
            if( check1 ) player1->removeWeapon(i);
        }
    }
    for(int i=0;i<weapon_list2.size();i++){
        Weapon* p_weapon = weapon_list2.at(i);
        if(p_weapon){
            bool check = Collision::checkCollision(p_weapon->getRect(), player1->GetRectFrame());
            if( check ) player2->removeWeapon(i);
            bool check1 = Collision::checkCollision(p_weapon->getRect(), player2->GetRectFrame());
            if( check1 ) player2->removeWeapon(i);
        }
    }
    player1->render();
    player2->render();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}
