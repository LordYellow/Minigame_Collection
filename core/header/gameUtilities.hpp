//
// Created by Raphael Straub on 19.09.18.
//

#ifndef MINIGAME_COLLECTION_GAMEUTILITIES_HPP
#define MINIGAME_COLLECTION_GAMEUTILITIES_HPP

#include <SDL2/SDL.h>

namespace gameUtilities {
    void drawChessField(SDL_Renderer *renner, SDL_Window *win);

    inline SDL_Rect getRectOnChessField(int pia, SDL_Window *win);
}

SDL_Rect gameUtilities::getRectOnChessField(int pia, SDL_Window *win) {
    int wx, wy;
    SDL_GetWindowSize(win, &wx, &wy);
    return {pia % 8 * ((wx / 8 < wy / 8 ? wx : wy) / 8) + ((wx / 8 < wy / 8 ? wx : wy) / 8 == wy / 8 ?
                                                           (wx - wy) / 2 : 0),
            (pia / 8) * ((wx / 8 < wy / 8 ? wx : wy) / 8) + ((wx / 8 < wy / 8 ? wx : wy) / 8 == wy / 8 ?
                                                             0 : (wy - wx) / 2),
            (wx / 8 < wy / 8 ? wx : wy) / 8,
            (wx / 8 < wy / 8 ? wx : wy) / 8};
}

#endif //MINIGAME_COLLECTION_GAMEUTILITIES_HPP
