//
//  Sprite.hpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/11/23.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class Sprite{
public:
    int repeatX = 1;
    int repeatY = 1;
    SDL_Rect location;
    
    SDL_Surface* dstSurface = NULL;
    SDL_Renderer* gRenderer = NULL;
    SDL_Texture* image = NULL;
    
    Sprite(SDL_Rect location, SDL_Surface* dstSurface, SDL_Renderer* gRenderer, const char* imageFile);
    Sprite(SDL_Rect location, SDL_Surface* dstSurface, SDL_Renderer* gRenderer, const char* imageFile, int repeatX, int repeatY);
    ~Sprite();
    
};
#endif /* Sprite_hpp */
