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
    GameObject* grass = new GameObject(0, 680, 40, 40, "/Users/colinmaloney/Documents/Code/C++/SDL_2023/SDL_2023/images/Grass.png");
    
    GameObject* pawn = new Pawn(340, 520, 40, 80, "/Users/colinmaloney/Documents/Code/C++/SDL_2023/SDL_2023/images/Character.png");
    
    GameObject* objects[2] = {grass, pawn};
    
    
};

#endif /* Mario_hpp */
