// Class Target

#include "Target.h"
#include <iostream>

using namespace std;

Target::Target(){
	x_target = 2;
	y_target = 2;
}

Target::Target(int q, int p){
	x_target = q;
	y_target = p;
}

Target::~Target(){

}

int Target::getx_target() const{
	return x_target;
}

int Target::gety_target() const{
	return y_target;
}

void Target::setx_target(int q){
	x_target = q;
}

void Target::sety_target(int p){
	y_target = p;
}