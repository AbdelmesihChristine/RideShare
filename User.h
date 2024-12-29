#ifndef USER_H
#define USER_H

#include <string>
#include "Location.h"

class User {
protected:
    std::string id;
    std::string name;
    int rating;
    Location loc;
public:
    User(char code, int idNum, const std::string& name, int rating, const Location& loc);
    virtual ~User();

    // Getters
    const std::string& getId() const;
    const std::string& getName() const;
    int getRating() const;
    const Location& getLocation() const;

    // Setters
    void setRating(int rating);
    void setLocation(const Location& loc);
    void setLocation(int x, int y);

    virtual void print() const;
};

#endif