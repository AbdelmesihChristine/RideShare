#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include "Drawable.h"
#include "Location.h"
#include "View.h"

class Customer : public User, public Drawable {
private:
    // Class variables
    static const char code;       // Should be set to 'C'
    static int nextId;            // Produces the next id number
    static const int custLayer;   // Initialized to 3

public:
    // Constructor
    Customer(const std::string& name, int rating, const Location& loc);

    // Override the draw function
    void draw(View& view) override;

    // Static function to compare names (for sorting)
    static int compNames(Customer* c1, Customer* c2);

    // Static function to reset nextId
    static void resetNextId();

    // Override the print function
    void print() const override;
};

#endif