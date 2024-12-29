#include "Customer.h"
#include <iostream>

// Initialize static class variables
const char Customer::code = 'C';
int Customer::nextId = 0;
const int Customer::custLayer = 3;

// Constructor implementation
Customer::Customer(const std::string& name, int rating, const Location& loc)
    : User(code, nextId + 1, name, rating, loc), Drawable(custLayer) {
    ++nextId;
    std::cout << "Customer added: " << name << ", ID: " << id << std::endl;
}

// Override the draw function
void Customer::draw(View& view) {
    view.drawCustomer(loc.getX(), loc.getY(), name[0]);
}

// Static function to compare Customer names alphabetically
int Customer::compNames(Customer* c1, Customer* c2) {
    if (c1->getName() < c2->getName())
        return -1;
    else if (c1->getName() > c2->getName())
        return 1;
    else
        return 0;
}

// Static function to reset nextId
void Customer::resetNextId() {
    nextId = 0;
}

// Override the print function
void Customer::print() const {
    std::cout << "Customer: " << name << " ";
    User::print();
}