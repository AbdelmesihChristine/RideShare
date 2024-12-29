#include "User.h"
#include <iostream>

User::User(char code, int idNum, const std::string& name, int rating, const Location& loc)
    : name(name), rating(rating), loc(loc) {
    id = code + std::to_string(idNum);
}

User::~User() {}

const std::string& User::getId() const { return id; }
const std::string& User::getName() const { return name; }
int User::getRating() const { return rating; }
const Location& User::getLocation() const { return loc; }

void User::setRating(int rating) { this->rating = rating; }
void User::setLocation(const Location& loc) { this->loc = loc; }
void User::setLocation(int x, int y) { loc.setLocation(x, y); }

void User::print() const {
    std::cout << "ID: " << id << ", Rating: " << rating << ", Location: ";
    loc.print();
}