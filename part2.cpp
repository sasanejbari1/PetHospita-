#include <iostream>
#include <string>
#include "CatsRule.h"

using std::string;
using std::endl;
using std::cout;

template <typename T>
bool testAnswer(const string &nameOfTest, const T& received, const T& expected);


int main() {
  {
  	CatsRule cr;
    cout << "Test sequence 1\n";
  	cr.checkIn("dog", "Rover");
  	cr.checkIn("cat", "Felix");
  	cr.checkIn("rabbit", "Bunbun");
  	cr.checkIn("cat", "Tigre");
  	testAnswer("seePet", cr.seePet(), string("Felix")); 		// must return Felix
  	testAnswer("seePet", cr.seePet(), string("Tigre")); 		// must return Tigre
  	testAnswer("seePet", cr.seePet(), string("Rover")); 		// must return Rover
  	cr.checkIn("dog", "Lassie");
  	testAnswer("seePet", cr.seePet(), string("Bunbun")); 		// must return Bunbun
  	cr.checkIn("cat", "Kitty");
  	testAnswer("seePet", cr.seePet(), string("Kitty")); 		// must return Kitty
  	testAnswer("seePet", cr.seePet(), string("Lassie")); 		// must return Lassie
  	testAnswer("seePet", cr.seePet(), string()); 		// must return the empty string
  }
  {
  	CatsRule cr;
    cout << "Test sequence 2\n";
    cr.checkIn("dog", "Lassie");
    cr.checkIn("rabbit", "Bunbun");
  	cr.checkIn("dog", "Rover");
    testAnswer("seePet", cr.seePet(), string("Lassie")); 		// must return Lassie
    testAnswer("seePet", cr.seePet(), string("Bunbun")); 		// must return Bunbun
  	cr.checkIn("cat", "Felix");
  	cr.checkIn("cat", "Tigre");
  	testAnswer("seePet", cr.seePet(), string("Felix")); 		// must return Felix
  	testAnswer("seePet", cr.seePet(), string("Tigre")); 		// must return Tigre
  	testAnswer("seePet", cr.seePet(), string("Rover")); 		// must return Rover
    testAnswer("seePet", cr.seePet(), string()); 		// must return the empty string
  	cr.checkIn("cat", "Kitty");
  	testAnswer("seePet", cr.seePet(), string("Kitty")); 		// must return Kitty
  }

  return (0);
}

template <typename T>
bool testAnswer(const string &nameOfTest, const T& received, const T& expected) {
  if (received == expected) {
    cout << "PASSED " << nameOfTest << ": expected and received " << received << endl;
    return true;
  }
  cout << "FAILED " << nameOfTest << ": expected " << expected << " but received " << received << endl;
  return false;
}
