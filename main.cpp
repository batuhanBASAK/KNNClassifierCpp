#include <iostream>
#include "Point.h"
#include "KNNClassifier.h"

using namespace std;
using namespace KNN;

int main() {
    KNNClassifier model(5, 0.8);

    model.readCSV("input.csv");

    model.fit();



    return 0;
}
