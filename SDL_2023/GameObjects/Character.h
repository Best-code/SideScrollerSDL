//
//  Character.h
//  SDL_2023
//
//  Created by Colin Maloney on 10/11/23.
//

#ifndef Character_h
#define Character_h

#include <stdio.h>
#include "Pawn.hpp"

class Character : public Pawn
{
public:
    Sprite* character;
    
    Character(SDL_Rect location) : Pawn(location) {}
    
    void init(SDL_Surface* dstSurface, SDL_Renderer* gRenderer) override
    {
        velocity = 25;
        character = new Sprite(location, dstSurface, gRenderer, "/Users/colinmaloney/Documents/Code/C++/SDL_2023/SDL_2023/images/Character.png");
        sprites.push_back(character);
        
        this->dstSurface = dstSurface;
        this->gRenderer = gRenderer;
    }
    
    void draw() override{
        SDL_RenderCopyEx(gRenderer, character->image, NULL, &location, 0, NULL, facingRight ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL);
    }
    
    void handleInput(SDL_Event& e) override{
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
    
    
};



#endif /* Character_h */
