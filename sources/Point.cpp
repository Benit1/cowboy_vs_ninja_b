//
// Created by beni on 5/15/23.
//
#include <valarray>
#include "Point.hpp"
#include "iostream"

namespace ariel {
//Constructor with two arguments
    Point::Point(double X_axis, double Y_axis) : X_axis(X_axis), Y_axis(Y_axis) {}

// Default constructor that initializes the point at the origin (0,0)
    Point::Point() : X_axis(0), Y_axis(0) {}

//destructor
    Point::~Point() = default;


    double Point::distance(Point &other) {
        double dX = X_axis - other.X_axis;
        double dY = Y_axis - other.Y_axis;
        return std::sqrt(dX * dX + dY * dY);
    }

    void Point::print() {
        std::cout << "(" << X_axis << "," << Y_axis << ")" << std::endl;
    }

//Method that moves this point towards another point by a specified distance
//Using "Euclidean distance"
    Point Point::moveTowards(Point &src, Point &dest, double distance) {
        if (distance < 0) {
            throw std::invalid_argument("Distance cannot be less then 0");
        }
        // Calculate the x and y differences
        double dX = dest.X_axis - src.X_axis;
        double dY = dest.Y_axis - src.Y_axis;
        double dist_to_dest = std::sqrt(dX * dX + dY * dY);
        if (dist_to_dest <= distance) {
            return dest;
        }
        // Calculate the ratio
        double ratio = distance / dist_to_dest;

        double newX_coor = src.X_axis + ratio * dX;
        double newY_coor = src.Y_axis + ratio * dY;
        return Point(newX_coor, newY_coor);
    }

// == operator to check if this point is equal to other point
// Two points are the equals if their x and y coordinates are the same
    bool Point::operator==(Point &other) {
        return X_axis == other.X_axis && Y_axis == other.Y_axis;
    }

}

