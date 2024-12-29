#ifndef DRAWABLE_H
#define DRAWABLE_H

class View; // Forward declaration

class Drawable {
protected:
    int layer;
public:
    Drawable(int layer);
    virtual ~Drawable();
    virtual void draw(View&) = 0; // Pure virtual function
    static int compare(Drawable* d1, Drawable* d2);
};

#endif