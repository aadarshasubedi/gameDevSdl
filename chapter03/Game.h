#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Game {
private:
  SDL_Window*     m_pWindow;
  SDL_Renderer*   m_pRenderer;
  
  //int             m_currentFrame;
  
  bool            m_bRunning;
  
  GameObject*     m_go;
  GameObject*     m_player;
  GameObject*     m_enemy;
  
  std::vector<GameObject*>    m_gameObjects;
  
  
public:
  Game(){}
  ~Game(){}
  
  bool init( const char* title, int xpos, int ypos, int width, int height, int flags ) {
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
      //printf( "Error - Could not initialise SDL\n" );
      return false;
    }
    cout << "SDL successfully initialised" << endl;
    
    m_pWindow = SDL_CreateWindow( title, xpos, ypos, height, width, flags );

    if( m_pWindow != 0 ) {
      printf( "window created successfully\n" );
    } else {
      printf( "Error - Window not created\n" );
      return false;
    }
    
    m_pRenderer = SDL_CreateRenderer( m_pWindow, -1, 0 );
    
    if( m_pRenderer != 0 ) {
      cout << "Renderer created successfully" << endl;
      SDL_SetRenderDrawColor( m_pRenderer, 255, 0, 0, 255 );
    } else {
      cout << "Error - Unable to start renderer" << endl;
      return false;
    }
    
    if( !TextureManager::Instance() -> load( "assets/animate-alpha.png", "animate", m_pRenderer ) ) {
      return false;
    }
    
    m_go = new GameObject();
    m_player = new Player();
    
    m_go -> load( 100, 100, 128, 82, "animate" ); // sets the int x, int y, int width, int height, std::string textureID
    m_player -> load( 300, 300, 128, 82, "animate" ); // sets the int x, int y, int width, int height, std::string textureID
    
    m_gameObjects.push_back( m_go );
    m_gameObjects.push_back( m_player );
    
    m_enemy = new Enemy();
    m_enemy -> load( 0, 0, 128, 82, "animate" );
    m_gameObjects.push_back( m_enemy );
    
    m_bRunning = true;
    return true;
  }
  
  bool running() { return m_bRunning;  } 
  
  void handleEvents() {
    SDL_Event event;
    if( SDL_PollEvent( &event ) ) {
      switch( event.type ) {
        case SDL_QUIT:
          m_bRunning = false; break;
        default:
          break;
      }
    }
  }
  
  void update() {
    for( std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++ ) {
      m_gameObjects[i] -> update();
    }
  }
  
  void render() {
    SDL_RenderClear( m_pRenderer );
    
    for( std::vector<GameObject*>::size_type i = 0; i!= m_gameObjects.size(); i++ ) {
      m_gameObjects[i] -> draw( m_pRenderer );
    }
    
    SDL_RenderPresent( m_pRenderer );
  }
  
  void clean() {
    cout << "Killing SDL" << endl;
    SDL_DestroyWindow( m_pWindow );
    SDL_DestroyRenderer( m_pRenderer );
    SDL_Quit();
  }
  /*
  void draw() {
    for( std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++ ) {
      m_gameObjects[i] -> draw( m_pRenderer );
    }
  }
  */
};

#endif //GAME_H
