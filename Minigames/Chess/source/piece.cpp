//
// Created by Raphael Straub on 19.09.18.
//

#include <Minigames/Chess/header/piece.hpp>
#include <core/header/texture.hpp>
#include <core/header/gameUtilities.hpp>

piece::piece(int pos, bool color) {
    this->pos = pos;
    this->color = color;
}


void piece::draw(SDL_Renderer *renner, SDL_Window *win) {
    texture::renderTexture(renner, "./../resources/Chess/pieces.png",
                           gameUtilities::getRectOnChessField(this->pos, win), (this->id % 6) * 213,
                           (this->id / 6) * 213, 213, 213);
}

