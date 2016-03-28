#include "Game.h"
#include "TextureManager.h"

bool Game::init( const char* title, int xpos, int ypos, int width, int height, int flags ) {
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    std::cout << "Error - Could not initialise SDL" << endl;
    return false;
  }
  std::cout << "SDL successfully initialised" << endl;
  
  m_pWindow = SDL_CreateWindow( title, xpos, ypos, height, width, flags );

  if( m_pWindow != 0 ) {
    printf( "window created successfully\n" );
  } else {
    printf( "Error - Window not created\n" );
    return false;
  }
  
  m_pRenderer = SDL_CreateRenderer( m_pWindow, -1, 0 );
  
  if( m_pRenderer != 0 ) {
    std::cout << "Renderer created successfully" << endl;
    SDL_SetRenderDrawColor( m_pRenderer, 255, 0, 0, 255 );
  } else {
    std::cout << "Error - Unable to start renderer" << endl;
    return false;
  }
  
  if( !TheTextureManager::Instance() -> load( "assets/animate-alpha.png", "animate", m_pRenderer ) ) {
    return false;
  }
  
  m_bRunning = true;
  return true;
};

void Game::render() {
  SDL_RenderClear( m_pRenderer );
  
  TheTextureManager::Instance() -> draw( "animate", 0, 0, 128, 82, m_pRenderer, SDL_FLIP_NONE );
  TheTextureManager::Instance() -> drawFrame( "animate", 100, 100, 128, 82, 1, m_currentFrame, m_pRenderer, SDL_FLIP_NONE );
  
  SDL_RenderPresent( m_pRenderer );
};

void Game::update() {
  m_currentFrame = int( ( ( SDL_GetTicks() / 100 ) % 6 ) );
  
};

void Game::handleEvents() {
  SDL_Event event;
  if( SDL_PollEvent( &event ) ) {
    switch( event.type ) {
      case SDL_QUIT:
        m_bRunning = false; break;
      default:
        break;
    }
  }
};

void Game::clean() {
  std::cout << "Killing SDL" << endl;
  SDL_DestroyWindow( m_pWindow );
  SDL_DestroyRenderer( m_pRenderer );
  SDL_Quit();
};
