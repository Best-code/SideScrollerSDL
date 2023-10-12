//
//  Pawn.cpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/11/23.
//

#include "Pawn.hpp"
#include <iostream>

void Pawn::updateLocation()
{
    location.x = x;
    location.y = y;
}

void Pawn::handleInput(SDL_Event& e){
    if(e.type == SDL_KEYDOWN || e.key.state == SDL_PRESSED)
    {
        if (e.key.keysym.sym == SDLK_UP) {
            // Up Arrow
            y -= velocity;
        }  if (e.key.keysym.sym == SDLK_DOWN) {
            // Down Arrow
            y += velocity;
        }  if (e.key.keysym.sym == SDLK_LEFT) {
            // Left Arrow
            x -= velocity;
            facingRight = false;
        }  if (e.key.keysym.sym == SDLK_RIGHT) {
            // Right Arrow
            x += velocity;
            facingRight = true;
        }
        updateLocation();
    }
}

void Pawn::update(SDL_Event& e){
    handleInput(e);
}
