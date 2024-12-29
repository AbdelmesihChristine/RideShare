#include "Driver.h"
#include "View.h"
#include <iostream>

const char Driver::code = 'D';
const int Driver::driverLayer = 1;
int Driver::nextId = 0;

Driver::Driver(const std::string& name, int rating, Size size, const Location& loc)
    : User(code, nextId + 1, name, rating, loc), Drawable(driverLayer), size(size) {
    ++nextId;
    std::cout << "Driver added: " << name << ", ID: " << id << std::endl;
}

Driver::~Driver() {}

bool Driver::match(Size size, int rating) const {
    return (this->size >= size) && (abs(this->rating - rating) <= 2);
}

int Driver::getDistance(const Location& loc) const {
    return this->loc.getDistance(loc);
}

void Driver::draw(View& view) {
    view.drawDriver(loc.getX(), loc.getY(), name[0]);
}

void Driver::print() const {
    std::cout << "Driver: " << name << " ";
    User::print();
}

int Driver::compRatings(Driver* d1, Driver* d2) {
    return d2->getRating() - d1->getRating(); // For descending order
}

void Driver::resetNextId() {
    nextId = 0;
}