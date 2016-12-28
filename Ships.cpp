#include "Ships.h"

Ships::Ships(std::string name, int size){
    setSize(size);
    setName(name);
}

Ships::Ships(std::string name){
    setName(name);
}

void Ships::setSize(int size) {
    this->length = size;
}

void Ships::setName(std::string name) {
    this->name = name;
}

int Ships::getSize() {
    return this->length;
}

std::string Ships::getName() {
    return this->name;
}

void Ships::addPoints(std::vector<int> points) {
    this->positions.push_back(points);
}

void Ships::resetLocation() {
    this->positions.resize(0);
}
