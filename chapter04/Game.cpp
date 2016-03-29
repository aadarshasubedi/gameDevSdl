#include "Game.h"
#include "Player.h"
#include "Enemy.h"

Game* Game::s_pInstance = 0;


bool Game::init( const char* title, int xpos, int ypos, int width, int height, int flags ) {
  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    std::cout << "Error - Could not initialise SDL" << std::endl;
    return false;
  }
  std::cout << "SDL successfully initialised" << std::endl;
  
  m_pWindow = SDL_CreateWindow( title, xpos, ypos, height, width, flags );

  if( m_pWindow != 0 ) {
    std::cout << "window created successfully" << std::endl;
  } else {
    std::cout << "Error - Window not created" << std::endl;
    return false;
  }
  
  m_pRenderer = SDL_CreateRenderer( m_pWindow, -1, 0 );
  
  
  if( m_pRenderer != 0 ) {
    std::cout << "Renderer created successfully" << std::endl;
    SDL_SetRenderDrawColor( m_pRenderer, 255, 0, 0, 255 );
  } else {
    std::cout << "Error - Unable to start renderer" << std::endl;
    return false;
  }
  
  if( !TheTextureManager::Instance() -> load( "assets/animate-alpha.png", "animate", m_pRenderer ) ) {
    return false;
  }
  
  
  m_gameObjects.push_back( new Player( new LoaderParams( 100, 100, 128, 82, "animate" ) ) );
  m_gameObjects.push_back( new Enemy( new LoaderParams( 300, 300, 128, 82, "animate" ) ) );
  
  
  
  
  m_bRunning = true;
  return true;
};

void Game::render() {
  SDL_RenderClear( m_pRenderer );
  
  for( std::vector<GameObject*>::size_type i = 0; i!= m_gameObjects.size(); i++ ) {
    m_gameObjects[i] -> draw();
  }
  
  SDL_RenderPresent( m_pRenderer );
};

void Game::update() {
  
  for( std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++ ) {
    m_gameObjects[i] -> update();
  }
    
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
  std::cout << "Killing SDL" << std::endl;
  SDL_DestroyWindow( m_pWindow );
  SDL_DestroyRenderer( m_pRenderer );
  SDL_Quit();
};

