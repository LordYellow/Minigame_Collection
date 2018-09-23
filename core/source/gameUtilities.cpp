//
// Created by Raphael Straub on 19.09.18.
//

#include <core/header/gameUtilities.hpp>

#include "core/header/gameUtilities.hpp"

#include "./../header/texture.hpp"

void gameUtilities::drawChessField(SDL_Renderer *renner, SDL_Window *win) {
    // this is working like i want right now, but im not happy with this. it will be changed later
    SDL_Color fieldColor;
    int wx, wy, picsize, xr, yr;
    SDL_GetWindowSize(win, &wx, &wy);
    for (auto y = 0; y < 8; y++) {
        for (auto x = 0; x < 8; x++) {
            ((y % 2) ^ (x % 2)) ? (fieldColor = {50, 50, 50, 0}) : (fieldColor = {200, 200, 200, 0});
            picsize = (wx / 8 < wy / 8 ? wx : wy) / 8;
            yr = picsize == wy / 8 ? (wx - wy) / 2 : 0;
            xr = picsize == wy / 8 ? 0 : (wy - wx) / 2;

            texture::drawRectangle(renner, {y * (picsize) + yr, x * (picsize) + xr, picsize, picsize}, fieldColor,
                                   true);
        }
    }
}

void gameUtilities::checkOutSize(SDL_Window *win, int &x, int &y, int &s) {
    int wx, wy;
    SDL_GetWindowSize(win, &wx, &wy);
    s = (wx / 8 < wy / 8 ? wx : wy) / 8;
    x = s == wy / 8 ? (wx - wy) / 2 : 0;
    y = s == wy / 8 ? 0 : (wy - wx) / 2;
}
