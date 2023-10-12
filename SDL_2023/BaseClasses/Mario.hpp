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
#include "Character.h"

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
    GameObject* grass = new Grass({0, 680, 40, 40}, SCREEN_WIDTH/40, 1);
    GameObject* character = new Character({0,0,40,80});
    GameObject* objects[2] = {grass, character};
    
    
};

#endif /* Mario_hpp */
