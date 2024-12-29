#ifndef RIDESHARE_H
#define RIDESHARE_H

#include "List.h"
#include "Driver.h"
#include "Customer.h"
#include "Drawable.h"

class RideShare {
private:
    List<Driver*> drivers;
    List<Customer*> customers;
    List<Drawable*> drawables;

public:
    RideShare();
    ~RideShare();

    void addDriver(const std::string& name, Size size, int rating, const Location& loc);
    void addCustomer(const std::string& name, int rating, const Location& loc);

    Customer* getCustomer(const std::string& id);
    Driver* findRide(int rating, Size size, const Location& loc);

    void printCustomers() const;
    void printDrivers() const;

    void draw(View& view) const;
};

#endif