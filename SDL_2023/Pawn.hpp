//
//  Pawn.hpp
//  SDL_2023
//
//  Created by Colin Maloney on 10/11/23.
//

#ifndef Pawn_hpp
#define Pawn_hpp

#include "GameObject.hpp"

class Pawn : public GameObject{
public:
    Pawn(SDL_Rect location) : GameObject(location) {}
    
    int velocity = 5;
    
    void update(SDL_Event& e) override;
    void handleInput(SDL_Event& e) override;
    void updateLocation() override;
    
};

#endif /* Pawn_hpp */
