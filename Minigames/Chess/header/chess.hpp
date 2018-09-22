//
// Created by Raphael Straub on 19.09.18.
//

#ifndef MINIGAME_COLLECTION_CHESS_HPP
#define MINIGAME_COLLECTION_CHESS_HPP

#include "./../../../core/header/game.hpp"
#include "./piece.hpp"

#include <array>
#include <vector>

class chess : public game {
public:
    chess(SDL_Window *win, SDL_Renderer *renner, bool *running);

    ~chess() override = default;

    void run() override;

private:
    void handleEvents() override;

    void highlightField();

    std::array<int, 64> fieldHighlighting;
    std::vector<std::unique_ptr<piece> > pieces;
    bool turn = false, dragAndDrop = false;

};

#endif //MINIGAME_COLLECTION_CHESS_HPP