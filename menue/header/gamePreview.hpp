//
// Created by Raphael Straub on 16.09.18.
//

#ifndef MINIGAME_COLLECTION_GAMEPREVIEW_HPP
#define MINIGAME_COLLECTION_GAMEPREVIEW_HPP

#include "./../../core/header/definitions.hpp"

class gamePreview {
public:
    gamePreview(int id, std::string name, std::string description, std::string thumbnail);

    int getID();

    std::string getThumbnail();

    std::string getName();

    std::string getDescription();

private:
    int id;
    std::string name;
    std::string description;
    std::string thumbnail;
};

#endif //MINIGAME_COLLECTION_GAMEPREVIEW_HPP
