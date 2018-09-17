//
// Created by Raphael Straub on 17.09.18.
//

#ifndef MINIGAME_COLLECTION_TEXTURE_HPP
#define MINIGAME_COLLECTION_TEXTURE_HPP

#include "./definitions.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class texture {
public:

    static void renderTexture(SDL_Renderer *renner, std::string kindOfTexture, SDL_Rect dst);

    static void drawRectangle(SDL_Renderer *renner, SDL_Rect dst, SDL_Color color, bool fill);

    static void writeText(SDL_Renderer *renner, std::string message, SDL_Rect dst, int fontSize, SDL_Color color);

private:
    texture() = default; // you are not allowed to create such an object
    static SDL_Rect rectangle;
};

#endif //MINIGAME_COLLECTION_TEXTURE_HPP
