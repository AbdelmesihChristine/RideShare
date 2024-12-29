#ifndef DRIVER_H
#define DRIVER_H

#include "User.h"
#include "Drawable.h"
#include "defs.h"

class Driver : public User, public Drawable {
private:
    Size size;
    static const char code;
    static const int driverLayer;
    static int nextId;
public:
    Driver(const std::string& name, int rating, Size size, const Location& loc);
    ~Driver();

    bool match(Size size, int rating) const;
    int getDistance(const Location& loc) const;
    void draw(View& view) override;
    void print() const override;

    static int compRatings(Driver* d1, Driver* d2);
    static void resetNextId();
};

#endif