#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

class Game
{
public:

    Game();
    ~Game();

    void init(const char* title, int width, int height);
    void handleEvents();
    void update();
    bool running(){ return isRunning; }
    void render();
    void clean();
    static SDL_Renderer *renderer;
    static SDL_Event event;

private:
    bool isRunning = true;
    int cnt= 0;
    SDL_Window *window;

};


#endif // GAME_H_INCLUDED
