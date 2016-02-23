#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "GameObject.h"

class Player : public GameObject {
  public:
    
    void update() {
      //std::cout << "update player";
      m_x = 10;
      m_y = 20;
    }
    
};

#endif //PLAYER_H
