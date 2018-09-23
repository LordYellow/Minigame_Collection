//
// Created by Raphael Straub on 19.09.18.
//

#include <Minigames/Chess/header/piece.hpp>
#include <core/header/texture.hpp>
#include <core/header/gameUtilities.hpp>
#include <vector>

piece::piece(int pos, bool color, std::array<int, 64> *field) {
    this->pos = pos;
    this->color = color;
    (*field)[pos] = gameUtilities::boolToNegative(color);
}


void piece::draw(SDL_Renderer *renner, SDL_Window *win) {
    texture::renderTexture(renner, "./../resources/Chess/pieces.png",
                           gameUtilities::getRectOnChessField(this->pos, win), (this->id % 6) * 213,
                           (this->id / 6) * 213, 213, 213);
}

bool piece::doMove(int newPos, std::array<int, 64> &pField, std::array<int, 64> &field,
                   std::vector<std::unique_ptr<piece> > &pieces, std::string &lastMove) {
    DEB_MSG_1(_T(newPos))
    DEB_MSG_1(_T(pField[newPos]))
    if (pField[newPos] != POSSIBLE) return false;
    field[this->getPos()] = 0;
    field[newPos] = gameUtilities::boolToNegative(this->getColor());
    for (auto i = 0; i < pieces.size(); i++) {
        if (pieces[i]->getPos() == newPos) {
            pieces.erase(pieces.begin() + i);
            break;
        }
    }

    this->signMove(lastMove, newPos);
    this->pos = newPos;

    return true;
}

