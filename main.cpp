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

//    vector<float> coordinates;
//    coordinates.push_back(49.40);
//    coordinates.push_back(73);
//    coordinates.push_back(64.30);

//    cout << model.predict(coordinates) << endl;

    return 0;
}
