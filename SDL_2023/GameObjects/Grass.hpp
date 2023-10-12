//
//  Grass.hpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/11/23.
//

#ifndef Grass_hpp
#define Grass_hpp

#include <stdio.h>
#include "GameObject.hpp"

class Grass : public GameObject
{
public:
    Sprite* grass;

    Grass(SDL_Rect location) : GameObject(location) {}
    
    void init(SDL_Surface* dstSurface, SDL_Renderer* gRenderer) override
    {
     grass = new Sprite(location, dstSurface, gRenderer, "/Users/colinmaloney/Documents/Code/C++/SDL_2023/SDL_2023/images/Grass.png");
        sprites.push_back(grass);
    
        this->dstSurface = dstSurface;
        this->gRenderer = gRenderer;
    }
    
    
};

#endif /* Grass_hpp */
