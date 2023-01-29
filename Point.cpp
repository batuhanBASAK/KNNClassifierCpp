#include "Point.h"
#include <cstdlib>

namespace KNN {


    // Constructor method that takes coordinates, value
    // and dimension information of Point
    Point::Point(const vector<float>& c, int val, int d){
        this->value = val;

        if (d < 1) {
            cout << "Error: Dimension cannot be less than 1" << endl;
            exit(EXIT_FAILURE);
        }

        this->dimension = d;

        for (int i = 0; i < c.size() && i < dimension; i++)
            this->coordinates.push_back(c[i]);
    }

    Point::Point(const float arr[], int value, int dimension) {
        if (dimension < 1) {
            cout << "dimension cannot be 0 or a negative number!!!" << endl;
            exit(EXIT_FAILURE);
        }
        this->dimension = dimension;
        for (int i = 0; i < dimension; i++) {
            this->coordinates.push_back(arr[i]);
        }
        this->value = value;
    }



    // Returns the euclidean distance between *this and Point p.
    float Point::distance(const Point& p) const {
        float ans = 0.0f;
        for (int i = 0; i < this->dimension; i++)
            ans += pow(this->coordinates[i] - p.coordinates[i], 2);
            
        ans = sqrt(ans);
        return ans;
    }


    // friend function for operator overloading
    std::ostream& operator<< (std::ostream& stream, const Point& p){
        stream << "P(";
        for (int i = 0; i < p.dimension; i++) {
            stream << p.coordinates[i];
            if (i != p.dimension - 1)
                stream << ", ";
        }
        stream << ")"
            << ", dimension is " << p.dimension << "D"
            << ", value is " << p.value << endl;

        return stream;
    }
}
