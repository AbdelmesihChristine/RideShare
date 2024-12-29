# RideShare: An Uber-like Application

## 1. Introduction
**RideShare** is a C++ application that models an Uber-like ride-hailing system. It showcases advanced OOP principles such as class hierarchies, multiple inheritance, polymorphism, templates, function pointers, and the Visitor design pattern for multiple dispatch.

It allows you to:
- Create and manage **Drivers** and **Customers** in a virtual city.
- Coordinate **ride requests** based on location, vehicle size, and rating constraints.
- Visually represent all **Drivers** and **Customers** on a map via a `View`.
- Utilize multiple inheritance by having both `Driver` and `Customer` inherit from a base user class (`User`) and a drawable interface (`Drawable`).

---

## 2. Video Demo
*(Right-click → “Open Link in New Tab” for best viewing.)* 

[![Watch the video](https://img.youtube.com/vi/nPX4p4XhKy0/hqdefault.jpg)](https://youtu.be/nPX4p4XhKy0)

---

## 3. Features and Learning Outcomes
- **Class Hierarchies & Multiple Inheritance**:  
  `Driver` and `Customer` inherit from both a `User` class and a `Drawable` class.
- **Polymorphism & Visitor Pattern**:  
  Used for rendering different object types on a map and for dispatching rides.
- **Templates & Function Pointers**:  
  The templated `List<T>` class uses a function pointer to manage sorted insertion (e.g., comparing ratings or names).
- **Memory Management**:  
  Proper destructors ensure that no memory leaks occur when objects are created or destroyed.
- **Advanced C++ Concepts**:  
  Demonstrates usage of `static` class members, function pointers, multiple dispatch (Visitor), and more.

---

## 4. Project Structure

├── main.cc           // Entry point for the interactive RideShare program  
├── Controller.*      // Manages application flow and user interactions  
├── View.*            // Menu display, input handling, draws the city map  
├── RideShare.*       // Manages Drivers and Customers, coordinates rides  
├── User.*            // Base class for all users (Customers/Drivers)  
├── Driver.*          // A user who can provide rides, also Drawable  
├── Customer.*        // A user who can request rides, also Drawable  
├── Drawable.*        // Abstract class for anything that can be drawn on the View  
├── Location.*        // Represents a city coordinate, uses Manhattan distance  
├── List.*            // A templated list for storing pointers (Driver*, Customer*, etc.)  
├── defs.h            // Contains global definitions (e.g., MAX_X, MAX_Y, enum Size)  
├── Makefile          // Build instructions (see snippet below)  
└── README.md         // This file

---

## 5. Core Concepts Implemented
1. **Multiple Inheritance & Abstract Base Classes**  
   - `Customer` and `Driver` both derive from `User` and `Drawable`.
2. **Visitor Design Pattern (Multiple Dispatch)**  
   - Each `Drawable` implements `draw(View&)`, allowing `View` to render them differently (drivers on roads, customers in buildings).
3. **Templates & Function Pointers**  
   - The `List<T>` class is templated and uses a compare function pointer for insertion order.
4. **Static Members**  
   - Used for ID generation (`nextId`) and comparison (`compNames`, `compRatings`).
5. **Memory Management**  
   - `RideShare` destructor cleans up dynamically allocated `Driver` and `Customer` objects.

---

## 6. Quick Start
1. **Clone or Download** this repository.
2. **Build** the project with the provided Makefile:
   make

This produces an executable, for example:  

RideShareTest (interactive + test application).  
Run the interactive program:  

./RideShareTest  
(To check for memory leaks, run valgrind ./RideShareTest, if installed.)  

Clean up (optional):  

make clean  
Removes the executable and .o files.  

---

## 7. Usage Example
After running ./RideShareTest, you may see a menu like:

1. Display Map
2. Print all drivers
3. Print all customers
4. Find a ride
5. (Additional test options)
6. Exit

Typical Workflow:

Add Drivers/Customers (this is done internally in Controller::initRideShare).  
Display Map: Renders a textual grid showing roads (Drivers) and buildings (Customers).  
Print All Drivers/Customers: Shows a list of each user’s ID, rating, and location.  
Find a Ride: Prompts you for a Customer ID, desired vehicle size, and destination. Locates the closest available Driver who matches the rating and size constraints, then moves both to the new location.

---

## 8. Classes Overview

**Location**
Holds (x, y) coordinates.
Computes Manhattan distance (getDistance()).
Example: Location loc(3,4);

**Drawable (Abstract)**
Declares draw(View&) as a pure virtual function.
Driver and Customer override draw() to depict themselves differently on the map.

**User (Base Class)**
Common fields: id, name, rating, Location.
Driver and Customer both inherit from it.

**Driver**
Has a Size (small, medium, or large) and a match(size, rating) method.
Inherits from User and Drawable.
Drawn by View on the “road” layers.

**Customer**
Inherits from User and Drawable.
Drawn by View in “building” areas.
Requests rides via RideShare::findRide(...).

**List<T>**
A templated container for pointer types (Driver*, Customer*, Drawable*).
Maintains sorted order via a user-supplied comparison function pointer.

**RideShare**
Holds three Lists: Driver*, Customer*, and Drawable*.
Coordinates adding/deleting, searching for matches (findRide()), and drawing objects via draw(View&).

**Controller**
Initializes RideShare with sample data.
Provides menu-based logic, calls displayMap(), findRide(), etc.

**View**
Responsible for textual input/output.
Maintains and draws the map array.
Offers helper methods like drawDriver(x, y, char) or drawCustomer(x, y, char).
