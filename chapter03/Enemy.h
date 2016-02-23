#ifndef ENEMY_H
#define ENEMY_H

#include "GameObject.h"

using namespace std;

class Enemy : public GameObject {
  public:
    void load( int x, int y, int width, int height, std::string textureID ) {
      GameObject::load( x, y, width, height, textureID );
    }
  
    void draw( SDL_Renderer* pRenderer ) {
      GameObject::draw( pRenderer );
    }
    
    void update() {
      m_y += 1;
      m_x += 1;
      m_currentFrame = int( ( ( SDL_GetTicks() / 100 ) % 6 ) );
      
    }
    
    void clean() {
      GameObject::clean();
    }
    
};


#endif //ENEMY_H
