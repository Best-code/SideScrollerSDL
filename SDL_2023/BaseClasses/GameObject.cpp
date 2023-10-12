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
}

void GameObject::init(SDL_Surface* dstSurface, SDL_Renderer* gRenderer)
{
    this->dstSurface = dstSurface;
    this->gRenderer = gRenderer;
}

void GameObject::draw(){
    for(auto* sprite : sprites)
    {
        SDL_RenderCopyEx(gRenderer, sprite->image, NULL, &sprite->location, 0, NULL, facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);
    }
}
GameObject::~GameObject(){
    SDL_FreeSurface(dstSurface);
}
