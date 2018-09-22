//
// Created by Raphael Straub on 22.09.18.
//

#ifndef MINIGAME_COLLECTION_PAWN_HPP
#define MINIGAME_COLLECTION_PAWN_HPP

#include "./piece.hpp"

class pawn : public piece {
public:
    pawn(int pos, bool color);

    ~pawn() override = default;

    void showMoves() override;

    bool doMove(int x, int y) override;
};

#endif //MINIGAME_COLLECTION_PAWN_HPP
