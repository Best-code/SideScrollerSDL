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
#include <string>
#include "Sprite.hpp"
#include <vector>

class GameObject {
public:
    GameObject(SDL_Rect location);
    GameObject(SDL_Rect location, int repeatX, int repeatY);
    
    int x, y, w, h;
    SDL_Rect location;
    
    SDL_Rect boundary;
    
    bool facingRight = 1;
    int repeatX = 1;
    int repeatY = 1;
    
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Surface* dstSurface;
    
    std::vector<Sprite*> sprites;
    
    virtual void init(SDL_Surface* dstSurface, SDL_Renderer* renderer);
    
    virtual void update(SDL_Event& e) {};
    virtual void handleInput(SDL_Event& e) {};
    virtual void updateLocation() {};
   // virtual void handleCollision(const SDL_Rect* a, const SDL_Rect* b) {};

    virtual void draw();
    
};

#endif /* GameObject_hpp */
