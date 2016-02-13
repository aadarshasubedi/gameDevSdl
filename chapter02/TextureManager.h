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

  std::map<std::string, SDL_Texture*> m_textureMap;

public:
  TextureManager(){}
  ~TextureManager(){}
  
  bool load( std::string fileName, std::string id, SDL_Renderer* pRenderer ) {
    pTempSurface = IMG_Load( fileName.c_str() );
    
    if( pTempSurface == 0 ) { return false; }
    
    pTexture = SDL_CreateTextureFromSurface( pRenderer, pTempSurface );
    SDL_FreeSurface( pTempSurface );
    
    if( pTexture != 0 ) {
      m_textureMap[id] = pTexture;
      return true;
    }
    return false; // reaching here means something went wrong
  }
  
  void draw( std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip ) {
    SDL_Rect srcRect;
    SDL_Rect destRect;
    
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx( pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip );
    
  }
  
  void drawFrame( std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip ) {
    SDL_Rect srcRect;
    SDL_Rect destRect;
    srcRect.x = width * currentFrame;
    srcRect.y = height * ( currentRow - 1 );
    srcRect.w = destRect.w = width;
    srcRect.h = destRect.h = height;
    destRect.x = x;
    destRect.y = y;
    
    SDL_RenderCopyEx( pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip );
  }
};


#endif //TEXTUREMANAGER_H
