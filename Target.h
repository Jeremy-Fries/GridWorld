// Class Target

#include <iostream>

using namespace std;

#ifndef TARGET_H
#define TARGET_H

class Target{
public:
	// Default Constructor
	Target();

	// Overload Constructor
	Target(int, int);

	// Destructor
	~Target();

	//Accessor Functions
	int getx_target() const;
		// getx_target - returns x position of target
	int gety_target() const;
		// gety_target - returns y position of target

	// Mutator Functions
	void setx_target(int);
	// setx_target - sets x_target to desired constant position in grid
	void sety_target(int);
	// sety_target - sets y_target to desired constant position in grid

private:
	// Variables 
	int x_target, y_target;

};

#endif // TARGET_H














