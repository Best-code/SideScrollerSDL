//
//  Mario.hpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/10/23.
//

#ifndef Mario_hpp
#define Mario_hpp

#include <stdio.h>
#include "Engine.hpp"
#include "GameObject.hpp"

class Mario : public Engine
{
public:
    const int SCREEN_HEIGHT = 720;
    const int SCREEN_WIDTH = 1280;
    
    SDL_Window* gWindow = NULL;
    SDL_Surface* gSurface = NULL;
    SDL_Renderer* gRenderer = NULL;
    
    GameObject* grass = new GameObject(200, 200, 40, 40, "/Users/colinmaloney/Documents/Code/C++/SDL_2023/SDL_2023/Grass.png");
    
    GameObject* objects[1] = {grass};
    
    SDL_Surface* image = NULL;
    
    std::string title;
    
    Mario(std::string title) : Engine(title) {}
    
    bool run();
    
    
    bool init();
    
    void gameObjectsInitialize();
    
    bool loadImage(std::string fileName);
    
    SDL_Surface* LoadImage_SDL(std::string fileName);
    
    void gameLoop();
    
    void draw();
    
    void close();
    
};

#endif /* Mario_hpp */
