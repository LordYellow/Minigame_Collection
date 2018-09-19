//
// Created by Raphael Straub on 15.09.18.
//

#include <menue/header/menue.hpp>
#include "Minigames/Testgame/test.hpp"
#include "./../../core/header/texture.hpp"

#define FONTSIZE 30

menue::menue() {
    //SDL init stuff
    if(SDL_Init(SDL_INIT_VIDEO) != 0){std::cout << "error: " << SDL_GetError() << std::endl; return;}
    if (TTF_Init() != 0) {
        std::cout << "error" << std::endl;
        SDL_Quit();
        return;
    }
    this->win = SDL_CreateWindow("Titel", 100, 200, 1000, 800, SDL_WINDOW_SHOWN);
    if(win == nullptr){std::cout << "winerror: " << SDL_GetError() << std::endl; SDL_Quit(); return;}
    this->renner = SDL_CreateRenderer(this->win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renner == nullptr){SDL_DestroyWindow(this->win); std::cout << "renderererror: " << SDL_GetError() << std::endl; SDL_Quit(); return;}

    //this sets the window resizable
    SDL_SetWindowResizable(this->win, SDL_TRUE);

    /**
     * if the window is Resizable i am able to click to an green button on the top left corner to
     * maximize the window, however i am not able to un-maximize it by clicking the green button
     * again. The following 4 lines will change that. This is not an acceptable solution and to be
     * honest i have no idea why this is even working, but i dont have a better solution right now
     */
    SDL_SetWindowFullscreen(this->win, SDL_GetWindowFlags(this->win) & SDL_WINDOW_FULLSCREEN_DESKTOP ? 0
                                                                                                     : SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_SetWindowFullscreen(this->win, SDL_GetWindowFlags(this->win) & SDL_WINDOW_FULLSCREEN_DESKTOP ? 0
                                                                                                     : SDL_WINDOW_FULLSCREEN_DESKTOP);

    //now the gameVector is filled with with the gamePreview
    this->gameVector.emplace_back(0, "Testgame", "This is a Testgame", "testimage.png");
    this->gameVector.emplace_back(0, "Testgame2",
                                  "This is another Testgame. Do you know that you can vote for PDF in a few Years?",
                                  "testimage2.png");
    this->gameVector.emplace_back(0, "Much Longer name to Test stuff", "This is another Testgame", "testimage3.png");
}

menue::~menue() {
    //the sdl stuff gets destroyed
    SDL_DestroyRenderer(this->renner);
    SDL_DestroyWindow(this->win);
    SDL_Quit();
}

void menue::display() {
    while(this->running){
        SDL_SetRenderDrawColor(this->renner, 0, 0, 0, 0);
        SDL_RenderClear(this->renner);

        //the gamePreview is displayed until the user selects a game
        this->handleEvents();
        this->displayGamePreview();

        SDL_RenderPresent(this->renner);\
        SDL_Delay(1);
    }
}

void menue::handleEvents() {
    while (SDL_PollEvent(&this->event)) {
        switch(this->event.type){
            case SDL_QUIT: this->running = false; break;
            case SDL_KEYDOWN: this->keys[this->event.key.keysym.sym] = 1; break;
            case SDL_KEYUP: this->keys[this->event.key.keysym.sym] = 0; break;
            case SDL_MOUSEWHEEL:
                if (event.wheel.x < 0) {
                    this->goToTheRight();
                } else if (event.wheel.x > 0) {
                    this->goToTheLeft();
                }
                break;
            default: break;
        }
    }

    //use this key to start the game you selected
    if(this->keys[SDLK_p]){
        this->executeGame();
    }

    //if you are unable to scroll in a horizontal direction
    if (this->keys[SDLK_DOWN]) {
        this->goToTheLeft();
    }

    //if you are unable to scroll in a horizontal direction
    if (this->keys[SDLK_UP]) {
        this->goToTheRight();
    }
}

void menue::executeGame() {
    //here you have to create the game. The number after case is the id of the Game
    switch (this->gameVector[this->pia].getID()) {
        case 0:
            this->spiel = new test(this->win, this->renner, &this->running);
            break;
        default: DEB_ERR("Selection Error")
            break;
    }
    this->spiel->run();
    delete this->spiel;
}

void menue::displayGamePreview() {
    //this will get the resolution of the game
    SDL_GetWindowSize(this->win, &this->winx, &this->winy);


    //this will change the position of the Games Name if the resolution is changed
    if (this->winx != this->currentx) {
        this->selection = static_cast<int>(this->selection * ((double) this->winx * (1.0 / this->currentx)));
        this->currentx = this->winx;
    }
    //this will draw the thumbnail
    texture::renderTexture(this->renner, ("./../resources/thumbnails/" + this->gameVector[pia].getThumbnail()),
                           {0, 0, this->winx, this->winy});

    //this will draw the Games Name
    texture::writeText(this->renner, this->gameVector[this->pia].getName(),
                       {this->selection, this->winy / 20, 0, 0}, FONTSIZE, {255, 255, 255, 0});

    //this will draw the Games Description
    texture::writeText(this->renner, this->gameVector[this->pia].getDescription(),
                       {static_cast<int>(this->winx / 2 -
                                         (this->gameVector[this->pia].getDescription().length() * FONTSIZE / 8.0)),
                        this->winy / 10, 0, 0}, FONTSIZE / 2, {255, 255, 255, 0});
}

void menue::goToTheRight() {
    //this will check if it is possible to scroll right
    if (!(this->pia == this->gameVector.size() - 1 && this->selection >
                                                      this->winx -
                                                      this->gameVector[this->gameVector.size() -
                                                                       1].getName().length() *
                                                      FONTSIZE / 2.0)) {
        //now it checks if it should move to the net gamepreview or not
        if (this->selection >
            this->winx + this->gameVector[this->pia].getName().length() * FONTSIZE / 4.0) {
            this->pia++;
            this->selection = -static_cast<int>(this->gameVector[this->pia].getName().length() *
                                                FONTSIZE / 2);
        }
        this->selection += 15;
    } else {
        //if its not possible to scroll right the position will be changed to the most right position
        this->selection = static_cast<int>(this->winx - this->gameVector[this->gameVector.size() -
                                                                         1].getName().length() *
                                                        FONTSIZE / 2.0);
    }
}

void menue::goToTheLeft() {
    //this will basically do the same as goToTheRight, but on the left side
    if (!(this->pia == 0 && this->selection <= 0)) {
        this->selection -= 15;
        if (this->selection <
            -static_cast<int>(this->gameVector[this->pia].getName().length() * FONTSIZE / 2)) {
            this->pia--;
            this->selection = this->winx;
        }
    } else {
        this->selection = 0;
    }
}


