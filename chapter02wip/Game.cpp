#include "Game.h"
#include "TextureManager.h"

bool Game::init( const char* title, int xpos, int ypos, int width, int height, bool fullscreen ) {

  int flags = 0;
  if( fullscreen ) {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "Error - Could not initialise SDL: %s\n", SDL_GetError() );
    return false; // could not in
  }
  printf( "SDL successfully initialised\n" );
  
  m_pWindow = SDL_CreateWindow( title, xpos, ypos, height, width, flags );

  if( m_pWindow != 0 ) {
    printf( "window created successfully\n" );
  } else {
    printf( "Error - Window not created: %s\n", SDL_GetError() );
    return false;
  }
  
  m_pRenderer = SDL_CreateRenderer( m_pWindow, -1, 0 );
  
  if( m_pRenderer != 0 ) {
    printf( "Renderer created successfully\n" );
    SDL_SetRenderDrawColor( m_pRenderer, 255, 0, 0, 255 );
  } else {
    printf( "Error - Unable to start renderer: %s\n", SDL_GetError() );
    return false;
  }
  
  m_bRunning = true;
  
  // not sure this should be here so removing
  //m_textureManager.load( "assets/animate-alpha.png", "animate", m_pRenderer );
  
  return true;
}

void Game::handleEvents() {
  SDL_Event event;
  if( SDL_PollEvent( &event ) ) {
    switch( event.type ) {
      case SDL_QUIT:
        m_bRunning = false;
      break;
      
      default:
      break;
    }
  }
}

void Game::update() {
  //m_sourceRectangle.x = 128 * int( ( (  SDL_GetTicks() / 100 ) % 6 ) );
  m_currentFrame = int( ( ( SDL_GetTicks() / 100 ) % 6 ) );
}

void  Game::render() {
  //printf( "rendering...\n" );
  SDL_RenderClear( m_pRenderer );
  
  m_textureManager.draw( "animate", 0, 0, 128, 82, m_pRenderer );
  m_textureManager.drawFrame( "animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer );
  
  //printf( "starting RenderCopy\n" );
  //SDL_RenderCopy( m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle );
  //SDL_RenderCopyEx( m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle, 0, 0, SDL_FLIP_HORIZONTAL );
  //SDL_RenderCopy( m_pRenderer, m_pTexture, 0, 0 );
  
  SDL_RenderPresent( m_pRenderer );
}

void  Game::clean() {
  printf( "killing SDL\n" );
  SDL_DestroyWindow( m_pWindow );
  SDL_DestroyRenderer( m_pRenderer );
  SDL_Quit();
}
