//
// Created by Raphael Straub on 16.09.18.
//

#include "test.hpp"

test::test(SDL_Window *win, SDL_Renderer *renner, bool* running): game(win,renner,running) {

}

void test::run() {
    while (*this->running) {
        SDL_SetRenderDrawColor(this->renner, this->color, 0, 0, 0);
        SDL_RenderClear(this->renner);

        this->handleEvents();

        SDL_RenderPresent(this->renner);\
        SDL_Delay(1);
    }
}

void test::handleEvents() {
    if (SDL_PollEvent(&this->event)) {
        switch (this->event.type) {
            case SDL_QUIT:
                *this->running = false;
                break;
            case SDL_KEYDOWN:
                this->keys[this->event.key.keysym.sym] = 1;
                break;
            case SDL_KEYUP:
                this->keys[this->event.key.keysym.sym] = 0;
                break;
            case SDL_MOUSEWHEEL:
                if (event.wheel.y > 0) {
                    if (this->color < 256)this->color--;
                } else if (event.wheel.y < 0) {
                    if (this->color >= 0)this->color++;
                }
                break;
        }
    }
}
