//
//  Sprite.cpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/11/23.
//

#include "Sprite.hpp"
Sprite::Sprite(SDL_Rect location, SDL_Surface* dstSurface, SDL_Renderer* gRenderer, const char* imageFile)
{
    this->location = location;
    this->dstSurface = dstSurface;
    this->gRenderer = gRenderer;
        
    SDL_Surface* tempImage = IMG_Load(imageFile);
    this->image = SDL_CreateTextureFromSurface(gRenderer, tempImage);
    SDL_FreeSurface(tempImage);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(image);
}
