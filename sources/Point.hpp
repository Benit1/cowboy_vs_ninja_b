//
// Created by beni on 5/15/23.
//

#ifndef COWBOY_VS_NINJA_POINT_H
#define COWBOY_VS_NINJA_POINT_H


namespace ariel {
    class Point {


        double X_axis;
        double Y_axis;

    public:
        Point(double X_axis, double Y_axis);

        Point();

        ~Point();

        double distance(Point &other);

        void print();

        Point moveTowards(Point &src, Point &dest, double distance);

        bool operator==(Point &other);

    };
}
#endif