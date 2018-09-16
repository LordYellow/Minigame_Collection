
#include "./core/header/definitions.hpp"
#include "menue/header/menue.hpp"

int filter(void *argumente, SDL_Event *event) {
    return (event->type != SDL_MULTIGESTURE &&
            event->type != SDL_DOLLARGESTURE && event->type != SDL_MULTIGESTURE &&
            event->type != SDL_FINGERMOTION && event->type != SDL_FINGERDOWN &&
            event->type != SDL_FINGERUP);
}

int main(){
    SDL_SetEventFilter(filter, nullptr);

    menue m;
    m.display();
}
