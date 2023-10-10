//
//  GameObject.hpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/10/23.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class GameObject {
public:
    int x, y, w, h;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Surface* dstSurface;
    SDL_Texture* image;
    SDL_Rect location;
    
    GameObject(int x, int y, int w, int h, SDL_Surface* dstSurface, SDL_Renderer* renderer, const char* imageFile);
    
    void draw();
    
    ~GameObject();
    
};

#endif /* GameObject_hpp */
