#include "Game.h"

int main( int argc, char* args[] ) {
  Game* g_game = 0;
  g_game = new Game();
  
  g_game->init( "Chapter 1", 100, 100, 640, 480, 0 );
  
  g_game->render();
  SDL_Delay( 5000 );
  g_game->clean();
  
  return 0;
}
