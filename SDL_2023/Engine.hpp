//
//  Engine.hpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/10/23.
//

#ifndef Engine_hpp
#define Engine_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>


class Engine{
public:
    const int SCREEN_HEIGHT = 720;
    const int SCREEN_WIDTH = 1280;
    
    SDL_Window* gWindow = NULL;
    SDL_Surface* gSurface = NULL;
    SDL_Surface* image = NULL;
    
    std::string title;
    
    Engine(std::string title) : title(title) {}
    
    bool run();
    
    bool init();
    
    bool loadImage(std::string fileName);
    
    SDL_Surface* LoadImage_SDL(std::string fileName);
    
    void close();
    
};
#endif /* Engine_hpp */
