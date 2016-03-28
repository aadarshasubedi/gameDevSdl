#include<iostream>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <map>

using namespace std;

#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

class TextureManager {
private:
  SDL_Surface*    pTempSurface;
  SDL_Texture*    pTexture;
  static TextureManager* s_pInstance;

  std::map<std::string, SDL_Texture*> m_textureMap;
  
  TextureManager(){}
public:
  
  ~TextureManager(){}
  
  bool load( std::string fileName, std::string id, SDL_Renderer* pRenderer );
  void draw( std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip );
  void drawFrame( std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip );
  
  static TextureManager* Instance() {
    if( s_pInstance == 0 ) {
      s_pInstance = new TextureManager();
      return s_pInstance;
    }
    return s_pInstance;
  }
};

typedef TextureManager TheTextureManager;


#endif //TEXTUREMANAGER_H
