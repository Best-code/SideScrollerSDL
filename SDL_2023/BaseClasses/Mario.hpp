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
#include "Pawn.hpp"
#include "Sprite.hpp"
#include "Grass.hpp"

class Mario : public Engine
{
public:
    const int SCREEN_HEIGHT = 720;
    const int SCREEN_WIDTH = 1280;
    
    std::string title;
    Mario(std::string title) : Engine(title) {}
    
    SDL_Window* gWindow = NULL;
    SDL_Surface* gSurface = NULL;
    SDL_Renderer* gRenderer = NULL;
    
    bool init() override;
    void gameLoop() override;
    void close() override;
    
    void gameObjectsInitialize();
    void drawGameObjects();
    
public:
    GameObject* grass = new Grass({0, 680, 40, 40});
    GameObject* grass1 = new Grass({0, 640, 40, 40});
    GameObject* grass2 = new Grass({0, 600, 40, 40});
    GameObject* objects[3] = {grass, grass1, grass2};
    
    
};

#endif /* Mario_hpp */
