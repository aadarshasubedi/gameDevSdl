#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "TextureManager.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game {
private:
  SDL_Window*     m_pWindow;
  SDL_Renderer*   m_pRenderer;
  
  int             m_currentFrame;
  bool            m_bRunning;
  
public:
  Game(){}
  ~Game(){}
  
  bool init( const char* title, int xpos, int ypos, int width, int height, int flags );
  
  void render();
  void update();
  void handleEvents();
  void clean();
  
  // a function to access the private running variable
  bool running() {
    return m_bRunning; 
  } 
};

#endif //GAME_H
