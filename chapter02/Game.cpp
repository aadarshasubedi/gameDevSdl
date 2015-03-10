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
  
  SDL_Surface* pTempSurface = SDL_LoadBMP( "assets/rider.bmp" );
  
  m_pTexture = SDL_CreateTextureFromSurface( m_pRenderer, pTempSurface );
  
  SDL_FreeSurface( pTempSurface );
  
  SDL_QueryTexture( m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h );
  
  m_destinationRectangle.x = m_sourceRectangle.x = 0;
  m_destinationRectangle.y = m_sourceRectangle.y = 0;
  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h;
  
  
  return true;
}

void  Game::render() {
  printf( "rendering...\n" );
  SDL_RenderClear( m_pRenderer );
  printf( "starting RenderCopy\n" );
  SDL_RenderCopy( m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle );
  
  SDL_RenderPresent( m_pRenderer );
}

void  Game::clean() {
  printf( "killing SDL\n" );
  SDL_DestroyWindow( m_pWindow );
  SDL_DestroyRenderer( m_pRenderer );
  SDL_Quit();
}
