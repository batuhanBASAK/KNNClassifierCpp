#ifndef KNN_CLASSIFIER_H
#define KNN_CLASSIFIER_H


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include "Point.h"

namespace KNN {

    using namespace std;

    class KNNClassifier {
    public:
        // Constructor method takes neighbours count
        KNNClassifier(int neighbours, float trainSize);

        // Method to read points from csv file that name is given
        void readCSV(string filename);

        // Fit method
        void fit();

        // Method to predict the value of point p
        int predict(const vector<float>& coordinates);

        // Measure the 
        float measureAccuracy();


    private:
        // The number of neighbours to consider
        int neighbours;
        vector<Point*> points;
        // Training sets Points
        vector<Point*> trainSet;
        // Testing sets Points
        vector<Point*> testSet;
        // Training set size
        float trainSize;
        // Test set size
        float testSize;

        // Find dimension of point which is acquired from file.
        int findDimension(string line);

        // Helper method for fit 
        // Basicly finds the next index that doesn't exists in
        // neighboursIndexes to start iteration from
        int findNonExistIndex(const vector<int>& neighboursIndexes);
    };
}


#endif
