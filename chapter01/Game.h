#include<iostream>
#include<SDL2/SDL.h>

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game {
private:
  SDL_Window *m_pWindow;
  SDL_Renderer *m_pRenderer;
  bool m_bRunning;
  
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
      SDL_SetRenderDrawColor( m_pRenderer, 255, 255, 255, 255 );
    } else {
      cout << "Error - Unable to start renderer" << endl;
      return false;
    }
    
    m_bRunning = true;
    return true;
  }
  
  void render() {
    SDL_RenderClear( m_pRenderer );
    SDL_RenderPresent( m_pRenderer );
  }
  
  void update(){}
  
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
  
  void clean() {
    cout << "Killing SDL" << endl;
    SDL_DestroyWindow( m_pWindow );
    SDL_DestroyRenderer( m_pRenderer );
    SDL_Quit();
  }
  
  // a function to access the private running variable
  bool running() {
    return m_bRunning; 
  } 
};

#endif //GAME_H
