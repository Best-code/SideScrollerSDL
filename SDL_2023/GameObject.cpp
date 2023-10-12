//
//  GameObject.cpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/10/23.
//

#include "GameObject.hpp"
#include <iostream>

GameObject::GameObject(int x, int y, int w, int h, std::string imageFile){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    this->imageFile = imageFile;
    
    location.x = x;
    location.y = y;
    location.w = w;
    location.h = h;
}

void GameObject::init(SDL_Surface* dstSurface, SDL_Renderer* gRenderer)
{
    this->dstSurface = dstSurface;
    this->gRenderer = gRenderer;
        
    SDL_Surface* image = IMG_Load(imageFile.c_str());
    this->image = SDL_CreateTextureFromSurface(gRenderer, image);
    SDL_FreeSurface(image);
}

void GameObject::draw(){
    SDL_RenderCopyEx(gRenderer, image, NULL, &location, 0, NULL, facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);
}

GameObject::~GameObject(){
    SDL_DestroyTexture(image);
    SDL_FreeSurface(dstSurface);
}
