//
// Created by Raphael Straub on 19.09.18.
//

#include <Minigames/Chess/header/chess.hpp>
#include <core/header/texture.hpp>
#include <Minigames/Chess/header/pawn.hpp>

#include "Minigames/Chess/header/chess.hpp"

#include "./../../../core/header/gameUtilities.hpp"

#define GETPOSITION ((this->mouseX-x)/s + (this->mouseY-y)/s * 8)

chess::chess(SDL_Window *win, SDL_Renderer *renner, bool *running) : game(win, renner, running) {
    this->fieldHighlighting.fill(0);
    this->field.fill(0);

    //pawns
    for (auto i = 0; i < 8; i++) {
        this->pieces.push_back(std::unique_ptr<piece>(new pawn(8 + i, true, &this->field)));
        this->pieces.push_back(std::unique_ptr<piece>(new pawn(48 + i, false, &this->field)));
    }
}

void chess::run() {
    while (*this->running) {
        SDL_SetRenderDrawColor(this->renner, 0, 0, 0, 0);
        SDL_RenderClear(this->renner);

        gameUtilities::drawChessField(this->renner, this->win);
        this->highlightField();
        for (auto &piece : this->pieces) {
            if (this->dragAndDrop && &(*piece) == this->selectedPiece) continue;
            piece->draw(this->renner, this->win);
        }
        int s = gameUtilities::getPicSize(this->win);
        if (this->dragAndDrop)
            texture::renderTexture(renner, "./../resources/Chess/pieces.png",
                                   {this->mouseX - s / 2, this->mouseY - s / 2, s, s},
                                   (this->selectedPiece->getID() % 6) * 213,
                                   (this->selectedPiece->getID() / 6) * 213, 213, 213);
        this->handleEvents();

        SDL_RenderPresent(this->renner);
        SDL_Delay(1);
    }
}

void chess::handleEvents() {
    int x, y, s;
    while (SDL_PollEvent(&this->event)) { // while instead of if. Is that better?
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
            case SDL_MOUSEBUTTONDOWN:
                gameUtilities::checkOutSize(this->win, x, y, s);
                SDL_GetMouseState(&this->mouseX, &this->mouseY);
                if (!this->pieceAtPosition(GETPOSITION)) break;
                this->dragAndDrop = true;
                break;
            case SDL_MOUSEBUTTONUP:
                gameUtilities::checkOutSize(this->win, x, y, s);
                SDL_GetMouseState(&this->mouseX, &this->mouseY);
                this->dragAndDrop = false;
                this->turn =
                        this->selectedPiece->doMove(GETPOSITION, this->fieldHighlighting, this->field, this->pieces,
                                                    this->lastMove)
                        == !this->turn;
                this->fieldHighlighting.fill(0);
                break;
            case SDL_MOUSEMOTION:
                SDL_GetMouseState(&this->mouseX, &this->mouseY);
            default:
                break;
        }
    }
}

void chess::highlightField() {
    for (auto i = 0; i < 64; i++) {
        switch (this->fieldHighlighting[i]) {
            case CHECK:
                texture::drawRectangle(this->renner, gameUtilities::getRectOnChessField(i, this->win), {255, 0, 0, 0},
                                       false);
                break;
            case SELECTED:
                texture::drawRectangle(this->renner, gameUtilities::getRectOnChessField(i, this->win), {0, 255, 0, 0},
                                       false);
                break;
            case POSSIBLE:
                texture::drawRectangle(this->renner, gameUtilities::getRectOnChessField(i, this->win), {255, 255, 0, 0},
                                       false);
                break;
            default:
                break;
        }
    }
}

bool chess::pieceAtPosition(int pos) {
    for (auto &piece : this->pieces) {
        if (piece->getPos() == pos && piece->getColor() == this->turn) {
            this->selectedPiece = &(*piece);
            this->fieldHighlighting = piece->showMoves(this->fieldHighlighting, this->field, this->lastMove);
            return true;
        }
    }
    return false;
}
