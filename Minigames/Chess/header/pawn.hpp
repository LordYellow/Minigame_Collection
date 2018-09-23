//
// Created by Raphael Straub on 22.09.18.
//

#ifndef MINIGAME_COLLECTION_PAWN_HPP
#define MINIGAME_COLLECTION_PAWN_HPP

#include "./piece.hpp"

class pawn : public piece {
public:
    pawn(int pos, bool color, std::array<int, 64> *field);

    ~pawn() override = default;

    std::array<int, 64>
    showMoves(std::array<int, 64> field, std::array<int, 64> &pField, std::string &lastMove) override;

private:

    void signMove(std::string &lastMove, int newPos) override;
};

#endif //MINIGAME_COLLECTION_PAWN_HPP
