//
// Created by Raphael Straub on 22.09.18.
//

#include <Minigames/Chess/header/pawn.hpp>

#include "Minigames/Chess/header/pawn.hpp"

pawn::pawn(int pos, bool color) : piece(pos, color) {
    this->id = 5 + color * 6;
}

void pawn::showMoves() {

}

bool pawn::doMove(int x, int y) {
    return false;
}
