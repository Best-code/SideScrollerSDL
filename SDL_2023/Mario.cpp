//
//  Mario.cpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/10/23.
//

#include "Mario.hpp"

bool Mario::init()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    
    //Initialize SDL_Image
    int IMG_Flags = IMG_INIT_JPG || IMG_INIT_PNG;
    if( !(IMG_Init(IMG_Flags) && IMG_Flags) )
    {
        printf( "SDL_Image could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    
    
    //Create gWindow
    gWindow = SDL_CreateWindow( title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if( gWindow == NULL )
    {
        printf( "gWindow could not be created! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    
    // Create Renderer
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_SOFTWARE);
    if(gRenderer == NULL)
    {
        printf( "SDL Renderer could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 1);
    
    
    //Get gWindow surface
    gSurface = SDL_GetWindowSurface( gWindow );
    if( gSurface == NULL)
    {
        printf( "SDL Surface could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    
    gameObjectsInitialize();
    
    return true;
}

void Mario::gameObjectsInitialize(){
    for(auto &go : objects)
    {
        go->init(gSurface, gRenderer);
        
    }
    
    grassSprite = new Sprite(grassLocation, gSurface, gRenderer, "/Users/colinmaloney/Documents/Code/C++/SDL_2023/SDL_2023/images/Grass.png");
    grass->sprites.push_back(grassSprite);
}

void Mario::drawGameObjects(){
    for(auto &go : objects)
    {
        go->draw();
    }
}

void Mario::gameLoop()
{
    // Keeping ggWindow open
    SDL_Event e;
    bool quit = false;
    while( quit == false )
    {
        while( SDL_PollEvent( &e ) )
        {
            if( e.type == SDL_QUIT )
                quit = true;
            
            // Player controls
//            pawn->update(e);
//                pawn->handleInput(e);
        }
       
        // Drawing to the screen
        SDL_RenderClear(gRenderer);
        drawGameObjects();
        SDL_RenderPresent(gRenderer);
    }
}

void Mario::close()
{
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    SDL_Quit();
}

