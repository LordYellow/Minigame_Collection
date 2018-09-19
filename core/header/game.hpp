//
// Created by Raphael Straub on 16.09.18.
//

#ifndef MINIGAME_COLLECTION_GAME_HPP
#define MINIGAME_COLLECTION_GAME_HPP

#include "./definitions.hpp"

#include <SDL2/SDL.h>
#include <unordered_map>

/**
 * An abstract class for all Games
 */
class game{
public:
    /**
     *
     * @param win is the window you play the game in
     * @param renner is the renderer for your game
     * @param running is a pointer to the boolean determing if the game is running or not
     */
    game(SDL_Window *win, SDL_Renderer *renner, bool* running);

    /**
     * default destructor
     */
    virtual ~game() = default;

    /**
     * Here runs the game. This has to be called 1 time
     */
    virtual void run() = 0;

protected:

    /**
     * This handele the events
     */
    virtual void handleEvents() = 0;


    SDL_Window *win;
    SDL_Renderer *renner;
    SDL_Event event;
    std::unordered_map<int, int> keys;
    bool *running;
};

#endif //MINIGAME_COLLECTION_GAME_HPP
