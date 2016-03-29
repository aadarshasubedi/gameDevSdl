#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "LoaderParams.h"
#include "TextureManager.h"

using namespace std;

class GameObject;  // forward declaration to prevent circular dependency

class Game {
private:
  SDL_Window*     m_pWindow;
  SDL_Renderer*   m_pRenderer;
  
  bool            m_bRunning;
  
  static Game*    s_pInstance;
  
  std::vector<GameObject*>  m_gameObjects;
  Game(){}
public:
  
  ~Game(){}
  
  bool init( const char* title, int xpos, int ypos, int width, int height, int flags );
  
  void render();
  void update();
  void handleEvents();
  void clean();
  
  static Game* Instance() {
    if( s_pInstance == 0 ) {
      s_pInstance = new Game();
      return s_pInstance;
    }
    return s_pInstance;
  }
  
  
  bool running() { return m_bRunning;  } 
  SDL_Renderer* getRenderer() const { return m_pRenderer; }
};

typedef Game TheGame;

#endif //GAME_H
