#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstdlib>
#include "defs.h"

template <typename T>
class List {
private:
    int numElements;
    T* elements;
    int (*compare)(T t1, T t2); // Pointer to a compare function
public:
    // Constructor
    List(int (*comp)(T t1, T t2));

    // Destructor
    ~List();

    // Other functions
    void add(T t);
    T remove(int index);
    T get(int index) const;
    int getSize() const;
    bool isFull() const;
    void clear();
};

template <typename T>
List<T>::List(int (*comp)(T t1, T t2)) : numElements(0), compare(comp) {
    elements = new T[MAX_ARRAY];
}

template <typename T>
List<T>::~List() {
    delete[] elements;
}

template <typename T>
void List<T>::add(T t) {
    if (numElements >= MAX_ARRAY) {
        std::cerr << "List is full" << std::endl;
        exit(1);
    }
    int i = numElements - 1;
    while (i >= 0 && compare(elements[i], t) > 0) {
        elements[i + 1] = elements[i];
        --i;
    }
    elements[i + 1] = t;
    ++numElements;
}

template <typename T>
T List<T>::remove(int index) {
    if (index < 0 || index >= numElements) {
        std::cerr << "Index out of bounds" << std::endl;
        exit(1);
    }
    T temp = elements[index];
    for (int i = index; i < numElements - 1; ++i) {
        elements[i] = elements[i + 1];
    }
    --numElements;
    return temp;
}

template <typename T>
T List<T>::get(int index) const {
    if (index < 0 || index >= numElements) {
        std::cerr << "Index out of bounds" << std::endl;
        exit(1);
    }
    return elements[index];
}

template <typename T>
int List<T>::getSize() const {
    return numElements;
}

template <typename T>
bool List<T>::isFull() const {
    return numElements >= MAX_ARRAY;
}

template <typename T>
void List<T>::clear() {
    numElements = 0;
}

#endif