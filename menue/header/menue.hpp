//
// Created by Raphael Straub on 15.09.18.
//

#ifndef MINIGAME_COLLECTION_MENUE_HPP
#define MINIGAME_COLLECTION_MENUE_HPP

#include "core/header/definitions.hpp"
#include "gamePreview.hpp"

#include <SDL2/SDL.h>
#include <unordered_map>
#include <vector>

class game;

class menue{
public:
    menue();
    ~menue();

    void display();

private:
    void handleEvents();

    void executeGame();

    void displayGamePreview();

    std::vector<std::string> getDescriptionInLines();

    std::vector<gamePreview> gameVector;
    SDL_Window *win;
    SDL_Renderer *renner;
    SDL_Event event;
    std::unordered_map<int, int> keys;
    bool running = true;
    game *spiel;
    int selection = 300, winx, winy, pia = 0, currentx = 1000;
};

#endif //MINIGAME_COLLECTION_MENUE_HPP
