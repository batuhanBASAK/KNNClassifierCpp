#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>


namespace KNN {

    using namespace std;

    struct Point {

        // Constructor method that takes coordinates, value,
        // and dimension information of Point
        Point(const std::vector<float>& c, int val, int d);

        // Returns the euclidean distance between *this and Point p.
        float distance(const Point& p);

        // Coodinates
        std::vector<float> coordinates;


        // friend function for operator overloading
        friend std::ostream& operator<< (std::ostream& stream, const Point& p);

        // Value
        int value;

        // Dimension of Point
        int dimension;
    };
}


#endif
