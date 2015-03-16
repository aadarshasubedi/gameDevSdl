#ifndef GAME_H
#define GAME_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

class Game {
  public:
    Game(){}
    ~Game(){}
    
    bool init( const char* title, int xpos, int ypos, int width, int height, bool fullscreen );
    
    void render();
    void update();
    void handleEvents();
    void clean();
    
    // a function to access the private running variable
    bool running() { return m_bRunning; }
    
    private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    
    SDL_Texture* m_pTexture; // the new SDL_Texture variable
    SDL_Rect m_sourceRectangle; // the first rectangle
    SDL_Rect m_destinationRectangle; // another rectangle
    
    bool m_bRunning;
};

#endif //GAME_H
