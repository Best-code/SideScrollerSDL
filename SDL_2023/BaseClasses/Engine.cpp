#include "Engine.hpp"

bool Engine::init()
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
    
    
    //Get gWindow surface
    gSurface = SDL_GetWindowSurface( gWindow );
    
    
    
    return true;
}

void Engine::gameLoop()
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
        
        //Update the surface
        SDL_UpdateWindowSurface( gWindow );
    }
}

bool Engine::run()
{
    if (!init())
    {
        printf("Failed to initialize.\n");
        return false;
    }
    
    gameLoop();
    
    close();
    
    return true;
}

SDL_Surface* Engine::LoadImage_SDL(std::string fileName){
    SDL_Surface* result = IMG_Load(fileName.c_str());
    if(result == NULL)
    {
        printf( "Unable to load image %s! SDL Error: %s\n", fileName.c_str(), SDL_GetError() );
        exit(0);
    }
    return result;
};

void Engine::close()
{
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

