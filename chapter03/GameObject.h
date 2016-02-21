#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "TextureManager.h"

using namespace std;

class GameObject {
  protected:
    int m_x;
    int m_y;
    std::string m_textureID;
    
    int m_currentFrame;
    int m_currentRow;
    
    int m_width;
    int m_height;
    std::vector<GameObject*>  m_gameObjects;

  public:
    virtual void load( int x, int y, int width, int height, std::string textureID ) {
      
      m_x = x;
      m_y = y;
      m_width = width;
      m_height = height;
      m_textureID = textureID;
      
      m_currentRow = 1;
      m_currentFrame = 1;
      
      
    }
    
    void draw( SDL_Renderer* pRenderer ) {
      for( std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++ ) {
        m_gameObjects[i] -> draw( m_pRenderer );
        
      }
      //TextureManager::Instance() -> drawFrame( m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, pRenderer, SDL_FLIP_NONE );
    }
    
    void update() {
      m_x += 1;
    }
    void clean() {}
    
};

#endif //GAMEOBJECT_H
