//
//  GameObject.cpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/10/23.
//

#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(SDL_Rect location){
    this->location = location;
    this->boundary = location;
}

GameObject::GameObject(SDL_Rect location, int repeatX, int repeatY){
    this->location = location;
    this->repeatX = repeatX;
    this->repeatY = repeatY;
    
    this->boundary = {location.x, location.y, location.w * repeatX, location.h * repeatY};
}

void GameObject::init(SDL_Surface* dstSurface, SDL_Renderer* gRenderer)
{
    this->dstSurface = dstSurface;
    this->gRenderer = gRenderer;
}

void GameObject::draw(){
    for(auto* sprite : sprites)
    {
        for(int y = 0; y < sprite->repeatY; y++)
        {
            SDL_Rect spriteHere = sprite->location;
            spriteHere.y += (spriteHere.h * y);
            for(int x = 0; x < sprite->repeatX; x++)
            {
                SDL_RenderCopyEx(gRenderer, sprite->image, NULL, &spriteHere, 0, NULL, facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);
                spriteHere.x += spriteHere.w;
            }
        }
    }
}
