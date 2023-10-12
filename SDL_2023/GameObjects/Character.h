//
//  Character.h
//  SDL_2023
//
//  Created by Colin Maloney on 10/11/23.
//

#ifndef Character_h
#define Character_h

#include <stdio.h>
#include "Pawn.hpp"

class Character : public Pawn
{
public:
    Sprite* character;

    Character(SDL_Rect location) : Pawn(location) {}
    
    void init(SDL_Surface* dstSurface, SDL_Renderer* gRenderer) override
    {
     character = new Sprite(location, dstSurface, gRenderer, "/Users/colinmaloney/Documents/Code/C++/SDL_2023/SDL_2023/images/Character.png");
        sprites.push_back(character);
    
        this->dstSurface = dstSurface;
        this->gRenderer = gRenderer;
    }
    
    
};



#endif /* Character_h */
