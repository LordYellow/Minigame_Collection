#include <utility>

//
// Created by Raphael Straub on 16.09.18.
//

#include <menue/header/gamePreview.hpp>

gamePreview::gamePreview(int id, std::string name, std::string description, std::string thumbnail) {
    this->id = id;
    this->name = std::move(name);
    this->description = std::move(description);
    this->thumbnail = std::move(thumbnail);
}

int gamePreview::getID() {
    return this->id;
}

std::string gamePreview::getThumbnail() {
    return this->thumbnail;
}

std::string gamePreview::getName() {
    return this->name;
}

std::string gamePreview::getDescription() {
    return this->description;
}
