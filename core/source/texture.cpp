//
// Created by Raphael Straub on 17.09.18.
//

#include <core/header/texture.hpp>

SDL_Rect texture::rectangle = {0, 0, 0, 0};

void texture::renderTexture(SDL_Renderer *renner, std::string kindOfTexture, SDL_Rect dst) {
    auto s = IMG_Load(kindOfTexture.c_str());
    auto texture1 = SDL_CreateTextureFromSurface(renner, s);
    int w, h;
    SDL_QueryTexture(texture1, nullptr, nullptr, &w, &h);
    rectangle.x = 0;
    rectangle.y = 0;
    rectangle.h = s->h;
    rectangle.w = s->w;
    SDL_RenderCopy(renner, texture1, &rectangle, &dst);
}

void texture::drawRectangle(SDL_Renderer *renner, SDL_Rect dst, SDL_Color color, bool fill) {

}

void texture::writeText(SDL_Renderer *renner, std::string message, SDL_Rect dst, int fontSize, SDL_Color color) {
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
