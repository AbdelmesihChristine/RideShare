#include "RideShare.h"

RideShare::RideShare()
    : drivers(Driver::compRatings), customers(Customer::compNames), drawables(Drawable::compare) {}

RideShare::~RideShare() {
    for (int i = 0; i < drivers.getSize(); ++i)
        delete drivers.get(i);
    for (int i = 0; i < customers.getSize(); ++i)
        delete customers.get(i);
}

void RideShare::addDriver(const std::string& name, Size size, int rating, const Location& loc) {
    Driver* driver = new Driver(name, rating, size, loc);
    drivers.add(driver);
    drawables.add(driver);
}

void RideShare::addCustomer(const std::string& name, int rating, const Location& loc) {
    Customer* customer = new Customer(name, rating, loc);
    customers.add(customer);
    drawables.add(customer);
}

Customer* RideShare::getCustomer(const std::string& id) {
    for (int i = 0; i < customers.getSize(); ++i) {
        if (customers.get(i)->getId() == id)
            return customers.get(i);
    }
    return nullptr;
}

Driver* RideShare::findRide(int rating, Size size, const Location& loc) {
    Driver* bestDriver = nullptr;
    int minDistance = MAX_BLOCKS * 2;
    for (int i = 0; i < drivers.getSize(); ++i) {
        Driver* driver = drivers.get(i);
        if (driver->match(size, rating)) {
            int distance = driver->getDistance(loc);
            if (distance < minDistance) {
                minDistance = distance;
                bestDriver = driver;
            }
        }
    }
    return bestDriver;
}

void RideShare::printCustomers() const {
    for (int i = 0; i < customers.getSize(); ++i)
        customers.get(i)->print();
}

void RideShare::printDrivers() const {
    for (int i = 0; i < drivers.getSize(); ++i)
        drivers.get(i)->print();
}

void RideShare::draw(View& view) const {
    for (int i = 0; i < drawables.getSize(); ++i)
        drawables.get(i)->draw(view);
}
