//
// Created by Raphael Straub on 19.09.18.
//

#ifndef MINIGAME_COLLECTION_PIECE_HPP
#define MINIGAME_COLLECTION_PIECE_HPP

#include "./../../../core/header/definitions.hpp"
#include <SDL2/SDL.h>
#include <array>

class piece {
public:
    piece(int pos, bool color, std::array<int, 64> *field);

    virtual ~piece() = default;

    virtual std::array<int, 64>
    showMoves(std::array<int, 64> field, std::array<int, 64> &pField, std::string &lastMove) = 0;

    virtual bool doMove(int newPos, std::array<int, 64> &pField, std::array<int, 64> &field,
                        std::vector<std::unique_ptr<piece> > &pieces, std::string &lastMove);

    void draw(SDL_Renderer *renner, SDL_Window *win);

    inline int getPos() const { return this->pos; }

    inline int getID() const { return this->id; }

    inline bool getColor() const { return this->color; }

protected:

    virtual void signMove(std::string &lastMove, int newPos) = 0;

    int id, pos;
    bool color;
};

#endif //MINIGAME_COLLECTION_PIECE_HPP
