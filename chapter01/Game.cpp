#include "Game.h"

bool Game::init( const char* title, int xpos, int ypos, int width, int height, int flags ) {
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    //printf( "Error - Could not initialise SDL\n" );
    return false; // could not in
  }
  printf( "SDL successfully initialised\n" );
  
  m_pWindow = SDL_CreateWindow( title, xpos, ypos, height, width, flags );

  if( m_pWindow != 0 ) {
    printf( "window created successfully\n" );
  } else {
    printf( "Error - Window not created\n" );
    return false;
  }
  
  m_pRenderer = SDL_CreateRenderer( m_pWindow, -1, 0 );
  
  if( m_pRenderer != 0 ) {
    printf( "Renderer created successfully\n" );
    SDL_SetRenderDrawColor( m_pRenderer, 255, 255, 255, 255 );
  } else {
    printf( "Error - Unable to start renderer\n" );
    return false;
  }
  
  m_bRunning = true;
  return true;
}

void  Game::render() {
  printf( "rendering...\n" );
  SDL_RenderClear( m_pRenderer );
  SDL_RenderPresent( m_pRenderer );
}

void  Game::clean() {
  printf( "killing SDL\n" );
  SDL_DestroyWindow( m_pWindow );
  SDL_DestroyRenderer( m_pRenderer );
  SDL_Quit();
}
