#include<SDL2/SDL.h>

#ifndef GAME_H
#define GAME_H

class Game {
  public:
    Game(){}
    ~Game(){}
    
    bool init( const char* title, int xpos, int ypos, int width, int height, int flags );
    
    void render();
    
    void clean();
    
    // a function to access the private running variable
    bool running() { return m_bRunning; }
    
    private:
    SDL_Window *m_pWindow;
    SDL_Renderer *m_pRenderer;
    
    bool m_bRunning;
};

#endif //GAME_H
