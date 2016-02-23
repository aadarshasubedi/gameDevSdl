#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject {
  public:
    void load( int x, int y, int width, int height, string textureID ) {
      GameObject::load( x, y, width, height, textureID );
    }
    
    void draw( SDL_Renderer* pRenderer ) {
      GameObject::draw( pRenderer );
    }
    
    void update() {
      m_x -+ 1;
    }
    
    void clean() {
      GameObject::clean();
    }
    
};

#endif //PLAYER_H
