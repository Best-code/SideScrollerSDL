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

void Pawn::update(SDL_Event& e){
    handleInput(e);
}
