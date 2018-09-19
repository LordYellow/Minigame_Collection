//
// Created by Raphael Straub on 16.09.18.
//

#ifndef MINIGAME_COLLECTION_TEST_HPP
#define MINIGAME_COLLECTION_TEST_HPP

#include "./../../core/header/game.hpp"

/**
 * test class this wont be commented
 */
class test : public game{
public:
    test(SDL_Window *win, SDL_Renderer *renner, bool* running);

    ~test() override = default;

    void run() override;

private:
    void handleEvents() override;

    uint color = 50;
};

#endif //MINIGAME_COLLECTION_TEST_HPP
