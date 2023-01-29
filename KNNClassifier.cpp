#include "KNNClassifier.h"
#include <algorithm>
#include <cstdlib>

namespace KNN {
    // Constructor method takes neighbours count
    KNNClassifier::KNNClassifier(int neighbours, float trainSize){
        if (neighbours < 1) {
            cout << "Error: Number of neighbours cannot be zero "
                << "or a negative number!!!" << endl;
            exit(EXIT_FAILURE);
        }
        this->neighbours = neighbours;

        if (trainSize <= 0.0f || trainSize >= 1.0f){
            cout << "Error: Invalid trainSize" << endl;
            exit(EXIT_FAILURE);
        }
        this->trainSize = trainSize;
        this->testSize= 1.0f - this->trainSize;
    }

    // Method to read points from csv file that name is given
    void KNNClassifier::readCSV(string filename){
        ifstream infile;
        infile.open(filename);
        if (infile.fail()) {
            cout << "Error: File " << filename 
                << " could not opened!!!" << endl;
            exit(EXIT_FAILURE);
        }

        string line;
        while (getline(infile, line)) {
            size_t pos = 0;
            string delim = ",";
            string token;
            int dimension = 0;
            vector<float> coordinates;
            while ((pos = line.find(delim)) != string::npos){
                token = line.substr(0, pos);
                coordinates.push_back(stof(token));
                line.erase(0, pos + delim.length());
                dimension++;
            }
            int value = stoi(line.substr(0, line.find("\n")));
            points.push_back(new Point(coordinates, value, dimension));
        }
        infile.close();
    }

    // Fit method
    void KNNClassifier::fit(){
        int i;
        // Set train set
        for (i = 0; i < trainSize * points.size(); i++) {
            trainSet.push_back(points[i]);
        }

        // Set test set
        for (i--; i < points.size(); i++) {
            testSet.push_back(points[i]);
        }
    }

    // Method to predict the value of point p
    int KNNClassifier::predict(const Point& p){
        // Int array list to hold nearest neighbours' indexes
        vector<int> neighboursIndexes;
        // nearest neighbours' point list
        vector<Point*> neighbourPoints;

        for (int i = 0; neighboursIndexes.size() < neighbours; i++) {
            int minDistanceIndex = findNonExistIndex(neighboursIndexes);
            float minDistance = p.distance(*testSet[minDistanceIndex]);
            for (int j = 0; j < trainSet.size(); j++) {
                float tmpDistance = p.distance(*testSet[j]);
                if (tmpDistance < minDistance) {
                    minDistanceIndex = j;
                    minDistance = tmpDistance;
                }
            }
            neighboursIndexes.push_back(minDistanceIndex);
            neighbourPoints.push_back(testSet[minDistanceIndex]);
        }

        int prediction = 0;
        for (int i = 0; i < neighbours; i++) {
            prediction += neighbourPoints[i]->value;
        }
        prediction /= neighbours;

        return prediction;
    }

    // Measure the 
    float KNNClassifier::measureAccuracy(){
        // STUB
        return 0.8;
    }


    // Helper method for fit 
    // Basicly finds the next index that doesn't exists in
    // neighboursIndexes to start iteration from
    int KNNClassifier::findNonExistIndex(const vector<int>& neighboursIndexes) {
        if (!neighboursIndexes.size())
            return 0;
        for (int i = 0; i < trainSet.size(); i++) {
            bool exists = false;
            for (int j = 0; j < neighboursIndexes.size(); j++)
                if (i == neighboursIndexes[j])
                    exists = true;
            if (!exists)
                return i;
        }
    }
}
