#include <iostream>


// Checks how an if statement processes a NULL pointer
// SPOILER: IT works as I would like! It runs the if statement
// test is considered to be a false bool


int main() {
	int* test = NULL;

	if (!test) {
		std::cout << "Works!" << std::endl;
	}
	
	return 0;
}
