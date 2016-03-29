#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "LoaderParams.h"
#include "TextureManager.h"
#include "Game.h"

class GameObject {
  protected:
    GameObject( const LoaderParams* pParams ) {}
    virtual ~GameObject() {}
  
  public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
};

#endif //GAMEOBJECT_H
