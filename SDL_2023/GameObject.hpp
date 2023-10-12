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

class GameObject {
public:
    int x, y, w, h;
    SDL_Rect location;
    
    bool facingRight = 1;
    
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Surface* dstSurface;
    SDL_Texture* image;

    std::string imageFile;
    
    GameObject(int x, int y, int w, int h, std::string imageFile);
    
    void init(SDL_Surface* dstSurface, SDL_Renderer* renderer);
    
    virtual void update(SDL_Event& e) {};
    virtual void handleInput(SDL_Event& e) {};
    virtual void updateLocation() {};

    void draw();
    
    ~GameObject();
    
};

#endif /* GameObject_hpp */
