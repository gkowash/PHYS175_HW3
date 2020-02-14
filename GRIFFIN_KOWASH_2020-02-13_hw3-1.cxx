#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//return sum of vector elements (with optional 'power' argument for exponent)
float vecSum(vector<float> Q, int power=1) {
  float total = 0;
  for (int i = 0; i < Q.size(); i++) {
    total += pow(Q[i], power);
  }
  return total;
}

//return mean of vector elements
float vecMean(vector<float> Q) {
  return vecSum(Q) / Q.size();
}

//return root-mean-square of vector elements
float vecRMS(vector<float> Q) {
  float sqSum = vecSum(Q, 2);
  float meanSqSum = sqSum / Q.size();
  return sqrt(meanSqSum);
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    cout << "Please specify file path." << endl;
    return 0;
  }

  //obtains file path and 
  string filename = string(argv[1]);
  ifstream inputFile(filename);
  vector<float> values;

  //read each line into a vector of floats
  float line;
  while (inputFile >> line) {
    values.push_back(line);
  }
  inputFile.close();
  
  cout << "Sum: " << vecSum(values) << endl;
  cout << "Mean: " << vecMean(values) << endl;
  cout << "RMS: " << vecRMS(values) << endl;
  
  return 1;
}
