//
// Created by Raphael Straub on 19.09.18.
//

#ifndef MINIGAME_COLLECTION_PIECE_HPP
#define MINIGAME_COLLECTION_PIECE_HPP

#include <SDL2/SDL.h>

class piece {
public:
    piece(int pos, bool color);

    virtual ~piece() = default;

    virtual void showMoves() = 0;

    virtual bool doMove(int x, int y) = 0;

    void draw(SDL_Renderer *renner, SDL_Window *win);

    inline int getPos() const { return this->pos; }

    inline int getID() const { return this->id; }

    inline bool getColor() const { return this->color; }

protected:
    int id, pos;
    bool color;
};

#endif //MINIGAME_COLLECTION_PIECE_HPP
