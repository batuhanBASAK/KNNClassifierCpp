#include <iostream>
#include "Point.h"
#include "KNNClassifier.h"

using namespace std;
using namespace KNN;

int main() {
    KNNClassifier model(5, 0.8);

    model.readCSV("input.csv");

    model.fit();
    model.measureAccuracy();



    /*
     * Some points to test
     * for point(46.50, 7.60, 98.60) expected value is 3
     * for point(11.40, 42.00, 0.50) expected value is 1
     */
    float c1[] = {46.50f, 7.6f, 98.6f};
    float c2[] = {11.4f, 42.0f, 0.5f};

    cout << model.predict(c1, 3) << endl;
    cout << model.predict(c2, 3) << endl;


    return 0;
}
