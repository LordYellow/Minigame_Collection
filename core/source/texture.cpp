//
// Created by Raphael Straub on 17.09.18.
//

#include <core/header/texture.hpp>

std::unordered_map<std::string, SDL_Texture *> texture::textures;

void texture::drawRectangle(SDL_Renderer *renner, SDL_Rect dst, SDL_Color color, bool fill) {
    SDL_SetRenderDrawColor(renner, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    if (fill) { SDL_RenderFillRect(renner, &dst); } else { SDL_RenderDrawRect(renner, &dst); }
}

void texture::renderTexture(SDL_Renderer *renner, std::string kindOfTexture, SDL_Rect dst, int posX, int posY, int tw,
                            int th) {

    if (!(textures.count(kindOfTexture))) {
        textures[kindOfTexture] = SDL_CreateTextureFromSurface(renner, IMG_Load(kindOfTexture.c_str()));
    }

    //to some stuff to scale it (?)
    int w, h;
    SDL_QueryTexture(textures[kindOfTexture], nullptr, nullptr, &w, &h);
    rectangle.x = posX;
    rectangle.y = posY;
    rectangle.h = (th == 0) ? h : th;
    rectangle.w = (tw == 0) ? w : th;

    //render it
    SDL_RenderCopy(renner, textures[kindOfTexture], &rectangle, &dst);

    //destroys the surface
    //SDL_FreeSurface(s);

    //destroys the texture
    //SDL_DestroyTexture(texture1);
}

void texture::writeText(SDL_Renderer *renner, std::string message, SDL_Rect dst, int fontSize, SDL_Color color) {

    //a Text is written dont question it
    TTF_Font *font = TTF_OpenFont("./../resources/fonts/UbuntuMono.ttf", fontSize);
    if (font == nullptr) {
        std::cout << TTF_GetError() << std::endl;
        return;
    }
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == nullptr) {
        std::cout << "surfaceeror" << std::endl;
        TTF_CloseFont(font);
        return;
    }
    SDL_Texture *text = SDL_CreateTextureFromSurface(renner, surf);
    if (text == nullptr) { std::cout << "textureerror" << std::endl; }
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    SDL_QueryTexture(text, nullptr, nullptr, &dst.w, &dst.h);
    SDL_RenderCopy(renner, text, nullptr, &dst);
}
