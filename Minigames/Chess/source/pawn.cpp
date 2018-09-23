//
// Created by Raphael Straub on 22.09.18.
//

#include <Minigames/Chess/header/pawn.hpp>
#include <core/header/gameUtilities.hpp>
#include <string>
#include "Minigames/Chess/header/pawn.hpp"

pawn::pawn(int pos, bool color, std::array<int, 64> *field) : piece(pos, color, field) {
    this->id = 5 + color * 6;
}

std::array<int, 64> pawn::showMoves(std::array<int, 64> field, std::array<int, 64> &pField, std::string &lastMove) {
    field[this->pos] = SELECTED;
    if (!pField[this->getPos() + 8 * gameUtilities::boolToNegative(this->getColor())]) {
        field[this->getPos() + 8 * gameUtilities::boolToNegative(this->getColor())] = POSSIBLE;
        if (((this->getPos() > 7 && this->getPos() < 16 && this->getColor()) ||
             (this->getPos() > 47 && this->getPos() < 56 && !this->getColor())) &&
            !pField[this->getPos() + 16 * gameUtilities::boolToNegative(this->getColor())]) {
            field[this->getPos() + 16 * gameUtilities::boolToNegative(this->getColor())] = POSSIBLE;
        }
    }
    return field;
}

void pawn::signMove(std::string &lastMove, int newPos) {
    if (newPos == this->pos + 16 * gameUtilities::boolToNegative(this->color))
        lastMove = "p" + std::to_string(this->pos + 8 * gameUtilities::boolToNegative(this->color));
    else
        lastMove = "p";
}

