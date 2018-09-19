//
// Created by Raphael Straub on 16.09.18.
//

#ifndef MINIGAME_COLLECTION_GAMEPREVIEW_HPP
#define MINIGAME_COLLECTION_GAMEPREVIEW_HPP

#include "./../../core/header/definitions.hpp"

///this class holds the preview for every game
class gamePreview {
public:
    /**
     * construtor. the on and only
     * @param id the id of the game. Has tp be added to your menue.cpp
     * @param name the name of the game
     * @param description the description of the game
     * @param thumbnail the name of the thumbnail (dont forget the .png)
     */
    gamePreview(int id, std::string name, std::string description, std::string thumbnail);

    /**
     * @return the id of the game
     */
    int getID();

    /**
     * @return the thumbnail of the game
     */
    std::string getThumbnail();

    /**
     * @return the name of the game
     */
    std::string getName();

    /**
     * @return the description of the game
     */
    std::string getDescription();

private:
    int id;
    std::string name;
    std::string description;
    std::string thumbnail;
};

#endif //MINIGAME_COLLECTION_GAMEPREVIEW_HPP
