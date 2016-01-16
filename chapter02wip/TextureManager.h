#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

#include <string.h>
#include <iostream>
#include <map>

class TextureManager {
  private:
    TextureManager(){}
    //~TextureManager(){}
    
  public:
    
    bool load( std::string filename, std::string id, SDL_Renderer* rRenderer );
    
    void draw( std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE );
    
    // drawframe
    void drawFrame( std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE );
    
    std::map<std::string, SDL_Texture*> m_textureMap;
    
};


#endif //TEXTURE_MANAGER_H
