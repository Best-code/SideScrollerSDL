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
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if(gRenderer == NULL)
    {
        printf( "SDL Renderer could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 1);
    
    
    //Get gWindow surface
    gSurface = SDL_GetWindowSurface( gWindow );
    
    
    grass = new GameObject(200, 200, 40, 40, gSurface, gRenderer, "/Users/colinmaloney/Documents/Code/C++/SDL_2023/SDL_2023/Grass.png");
    return true;
}

void Mario::draw()
{
    //Apply the PNG image
//    SDL_BlitSurface( image, NULL, gSurface, NULL );
    SDL_RenderClear(gRenderer);

    grass->draw();
    
    SDL_RenderPresent(gRenderer);
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
        }
        draw();
    }
}

bool Mario::run()
{
    if (!init())
    {
        printf("Failed to initialize.\n");
        return false;
    }

    image = LoadImage_SDL("/Users/colinmaloney/Documents/Code/C++/SDL_2023/SDL_2023/Grass.png");
    
    gameLoop();
    
    close();
    
    return true;
}


bool Mario::loadImage(std::string fileName)
{
    bool success = true;
    image = SDL_LoadBMP(fileName.c_str());
    if( image == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", fileName.c_str(), SDL_GetError() );
        success = false;
    }
    return success;
}

SDL_Surface* Mario::LoadImage_SDL(std::string fileName){
    SDL_Surface* result = IMG_Load(fileName.c_str());
    if(result == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", fileName.c_str(), SDL_GetError() );
        exit(0);
    }
    return result;
};

void Mario::close()
{
    SDL_DestroyWindow(gWindow);
    SDL_FreeSurface(image);
    SDL_Quit();
}

