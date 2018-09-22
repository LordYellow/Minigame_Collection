//
// Created by Raphael Straub on 17.09.18.
//

#ifndef MINIGAME_COLLECTION_TEXTURE_HPP
#define MINIGAME_COLLECTION_TEXTURE_HPP

#include "./definitions.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


namespace texture {

    /**
     * this will render your texture
     * @param renner the renderer you use
     * @param kindOfTexture the path to the texture you wanna draw
     * @param dst a recrtangle with the future destination of the texture
     */
    void
    renderTexture(SDL_Renderer *renner, std::string kindOfTexture, SDL_Rect dst, int = 0, int = 0, int = 0, int = 0);

    /**
     * at the moment this does nothing
     * @param renner
     * @param dst
     * @param color
     * @param fill
     */
    void drawRectangle(SDL_Renderer *renner, SDL_Rect dst, SDL_Color color, bool fill);

    /**
     * with this you are able to draw text
     * @param renner the renderer
     * @param message the message you wanna draw
     * @param dst the destination of the text
     * @param fontSize the fontsize
     * @param color the color of the texture
     */
    void writeText(SDL_Renderer *renner, std::string message, SDL_Rect dst, int fontSize, SDL_Color color);

    static SDL_Rect rectangle = {0, 0, 0, 0};
};

#endif //MINIGAME_COLLECTION_TEXTURE_HPP
