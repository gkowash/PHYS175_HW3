#include <iostream>
#include <cmath>

using namespace std;

/*
This program defines and demonstrates a FourVector class that contains the
energy and three-momentum of a particle.
 */

class FourVector {
  float E;
  float px;
  float py;
  float pz;
  float theta;
  float phi;
  
  public:
    //constructor method
    FourVector(float E_in, float px_in, float py_in, float pz_in) {
      E = E_in;
      px = px_in;
      py = py_in;
      pz = pz_in;
      theta = atan(sqrt(pow(px, 2) + pow(py, 2)) / pz); //polar angle
      phi = atan(py/px); //azimuthal angle
    }  
    //set new component values
    void setFourVector(float E_in, float px_in, float py_in, float pz_in) {
      E = E_in;
      px = px_in;
      py = py_in;
      pz = pz_in;
      theta = atan(sqrt(pow(px, 2) + pow(py, 2)) / pz); //polar angle
      phi = atan(py/px); //azimuthal angle
    }
    //return invariant mass
    float getMass() {
      return sqrt(pow(E, 2) - pow(px, 2) - pow(py, 2) - pow(pz, 2));
    }
    //return pseudorapidity
    float getEta() {
      return -log(tan(abs(theta)/2));
    }
    //return difference in azimuthal angle betwee two vectors
    float deltaPhi(FourVector &vec2) {
      float angle = abs(phi - vec2.phi);
      if (angle > 3.14159) {
	return 2*3.14159 - angle;
      }
      else {
	return angle;
      }
    }
    //return difference in pseudorapidity between two vectors
    float deltaEta(FourVector &vec2) {
      return abs(getEta() - vec2.getEta());
    }
};

int main() {
  //instantiate two four-vectors
  FourVector vec1(12.4, -0.3, 0.11, 2.5);
  FourVector vec2(36.6, 1.9, 5.3, -0.8);

  //print various quantities to console
  cout << "Vector1 invariant mass: " << vec1.getMass() << endl;
  cout << "Vector1 pseudorapidity: " << vec1.getEta() << endl;
  cout << "Vector2 invariant mass: " << vec2.getMass() << endl;
  cout << "Vecotr2 pseudorapidity: " << vec2.getEta() << endl;
  cout << "Difference in azimuthal angles: " << vec1.deltaPhi(vec2) << endl;
  cout << "Difference in pseudorapidity: " << vec1.deltaEta(vec2) << endl;
  cout << "Changing Vector1 to (3.3, 0.02, -1.0, -0.7)" << endl;
  vec1.setFourVector(3.3, 0.02, -1.0, -0.7);
  cout << "New Vector1 invariant mass: " << vec1.getMass() << endl;
  
  return 1;
};
