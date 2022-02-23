You are to implement a C++ class that will maintain the check-in procedure at the Cat’s rule! Pet Hospital. Pets entering the hospital are checked-in with their species and name, and then wait until they are called. Waiting pets are seen one-by-one according to this policy:
• Any waiting cat has higher priority than any other type of pet
• Among cats and others, pets must be selected in the order they checked-in
Implement your logic in class CatsRule. The class should have the following public methods:
·
·
CatsRule(); the default constructor
void checkIn(string species, string name);
A pet of the given species and name begins waiting to be called. Species is a lowercase
o
word. E.g., checkIn(“cat”, “Felix”), checkIn(“dog”, “Rover”).
· string seePet();
o return the name of the pet with the highest priority among those waiting. This pet then leaves the waiting room to be seen by the vet. If there are no pets, return the empty string.
These public member functions will be called from the provided main program and the answers checked there. Here is an example run:
CatsRule cr;
cr.checkIn(“dog”, “Rover”); cr.checkIn(“cat”, “Felix”); cr.checkIn(“rabbit”, “Bunbun”); cr.checkIn(“cat”, “Tigre”);
cr.seePet();
cr.seePet();
cr.seePet();
cr.checkIn(“dog”, “Lassie”); cr.seePet(); // must return Bunbun cr.checkIn(“cat”, “Kitty”);
cr.seePet(); cr.seePet(); cr.seePet();
// must return Kitty
// must return Lassie
// must return the empty string
// must return Felix // must return Tigre // must return Rover· You can modify the main function to test your code with different input cases to make sure the logic will work in the general case. We will test your code with different inputs.
· You are free to add other (public/private) member variables and methods if needed.
· You can implement all your code either in one header file called CatsRule.h or split the declaration and definition in CatsRule.h and CatsRule.cpp
Data structures: you are encouraged to use the C++ Standard Library containers. Required documentation: Write a short description of your approach as a long comment at
the beginning of CatsRule.h. Make clear what, if any, data structures you use and their roles. File submission: Upload as individual files (do not zip):
· CatsRule.h
· CatsRule.cpp (if used)
· Any additional files that you wrote
COMMAND TO COMPILE AND RUN CODE ON LINUX/TUFFIX:
clang++ -std=c++17 part2.cpp CatsRule.cpp ./a.out
