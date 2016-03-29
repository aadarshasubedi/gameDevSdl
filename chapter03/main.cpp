#include <iostream>
#include "Game.h"

using namespace std;

int main( int argc, char* args[] ) {
  cout << "game init attempt..." << endl;
  if( TheGame::Instance() -> init( "Chapter 3", 100, 100, 640, 480, false ) ) {
    cout << "game init success" << endl;
    while( TheGame::Instance() -> running() ) {
      TheGame::Instance() -> handleEvents();
      TheGame::Instance() -> update();
      TheGame::Instance() -> render();
      
      SDL_Delay( 10 );
    }
    
  } else {
    cout << "game init failure - " << SDL_GetError() << endl;
    return -1;
  }
  
  cout << "game closing" << endl;
  TheGame::Instance() -> clean();
  
  return 0;
}
