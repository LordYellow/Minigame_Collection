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

/**
 * with this class you are able to select the game you wanna play
 */
class menue{
public:

    /**
     * the constructor creates a window
     */
    menue();

    /**
     * the destructor will take care about the sdl stuff
     */
    ~menue();

    /**
     * this function will display the menue. call it only one time. if you want to call if again,
     * after you closed the first window you have to create a new menue class
     */
    void display();

private:

    /**
     * this will handle the events of the menue. its only called by display()
     */
    void handleEvents();

    /**
     * this will execute the selected game
     */
    void executeGame();

    /**
     * this will fill your screen with the game preview
     */
    void displayGamePreview();

    void goToTheRight();

    void goToTheLeft();

    ///here the gamePreviews are stored.
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
