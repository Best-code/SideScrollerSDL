//
//  GameObject.cpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/10/23.
//

#include "GameObject.hpp"

GameObject::GameObject(int x, int y, int w, int h, SDL_Surface* dstSurface, SDL_Renderer* gRenderer, const char* imageFile){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    
    this->dstSurface = dstSurface;
    this->gRenderer = gRenderer;
    
    location.x = x;
    location.y = y;
    location.w = w;
    location.h = h;
    
    SDL_Surface* image = IMG_Load(imageFile);
    this->image = SDL_CreateTextureFromSurface(gRenderer, image);
    SDL_FreeSurface(image);
}

void GameObject::draw(){
    SDL_RenderCopy(gRenderer, image, NULL, &location);
}

GameObject::~GameObject(){
    SDL_DestroyTexture(image);
}
