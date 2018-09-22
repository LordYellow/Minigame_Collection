//
// Created by Raphael Straub on 19.09.18.
//

#include <Minigames/Chess/header/chess.hpp>
#include <core/header/texture.hpp>
#include <Minigames/Chess/header/pawn.hpp>

#include "Minigames/Chess/header/chess.hpp"

#include "./../../../core/header/gameUtilities.hpp"

chess::chess(SDL_Window *win, SDL_Renderer *renner, bool *running) : game(win, renner, running) {
    this->fieldHighlighting.fill(0);

    this->pieces.push_back(std::unique_ptr<piece>(new pawn(8, true)));
}

void chess::run() {
    while (*this->running) {
        SDL_SetRenderDrawColor(this->renner, 0, 0, 0, 0);
        SDL_RenderClear(this->renner);

        gameUtilities::drawChessField(this->renner, this->win);
        this->highlightField();
        for (auto &piece : this->pieces) {
            piece->draw(this->renner, this->win);
        }
        this->handleEvents();

        SDL_RenderPresent(this->renner);
        SDL_Delay(1);
    }
}

void chess::handleEvents() {
    if (SDL_PollEvent(&this->event)) {
        switch (this->event.type) {
            case SDL_QUIT:
                *this->running = false;
                break;
            case SDL_KEYDOWN:
                this->keys[this->event.key.keysym.sym] = 1;
                break;
            case SDL_KEYUP:
                this->keys[this->event.key.keysym.sym] = 0;
                break;
        }
    }
}

void chess::highlightField() {
    for (auto i = 0; i < 64; i++) {
        switch (this->fieldHighlighting[i]) {
            case 1:
                texture::drawRectangle(this->renner, gameUtilities::getRectOnChessField(i, this->win), {255, 0, 0, 0},
                                       false);
                break;
            default:
                break;
        }
    }
}
