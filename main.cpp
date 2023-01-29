#include <iostream>
#include "Point.h"
#include "KNNClassifier.h"

using namespace std;
using namespace KNN;

int main() {
    KNNClassifier model(5, 0.8);

    model.readCSV("input.csv");

    model.fit();

    vector<float> coordinates;
    coordinates.push_back(3);
    coordinates.push_back(2);
    coordinates.push_back(4);

    cout << model.predict(coordinates) << endl;

    return 0;
}
