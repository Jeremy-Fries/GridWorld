// Class Agent

#include "Agent.h"
#include "Target.h"
#include "World.h"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std; // may not want to use... How whould I change this?

// Variables
int x_target, y_target;
double SMALL_NUM = 0.0001;	// GLOBAL variable use when need very small numbers

// Default Constructor
Agent::Agent(){
	x_agent = 1;
	y_agent = 1;
}

// Overload Constructor
Agent::Agent(int i, int j){
	x_agent = i;
	y_agent = j;
}

// Destructor
Agent::~Agent(){

}

// ------------------------------------------------------------------------------
double Agent::rand01(){
	double r;
	r = (double)rand() / RAND_MAX;
	return r;
}

int Agent::getx_agent(){
	return x_agent;
}
void Agent::setx_agent(int i){
	x_agent = i;
}
// ------------------------------------------------------------------------------
int Agent::gety_agent(){
	return y_agent;
}
void Agent::sety_agent(int j){
	y_agent = j;
}
// ------------------------------------------------------------------------------
int Agent::get_episodes(){
	return episodes;
}
void Agent::set_episodes(int e){
	episodes = e;
}
// ------------------------------------------------------------------------------
int Agent::get_timesteps(){
	return timesteps;
}
void Agent::set_timesteps(int t){
	timesteps = t;
}
// ------------------------------------------------------------------------------
int Agent::get_steps(){
	return steps;
}
void Agent::set_steps(int s){
	steps = s;
}
// ------------------------------------------------------------------------------
int Agent::get_total_steps(){
	return total_steps;
}
void Agent::set_total_steps(int ts){
	total_steps = ts;
}
// ------------------------------------------------------------------------------
int Agent::get_state(){
	return state;
}
void Agent::set_state(int s){
	state = s;
}
// ------------------------------------------------------------------------------ 
double Agent::get_alpha(){
	return alpha;
}
void Agent::set_alpha(double a){
	alpha = a;
}
// ------------------------------------------------------------------------------
double Agent::get_gamma(){
	return gamma;
}
void Agent::set_gamma(double g){
	gamma = g; 
}
// ------------------------------------------------------------------------------
double Agent::get_epsilon(){
	return epsilon;
}
void Agent::set_epsilon(double e){
	epsilon = e; 
}
// ------------------------------------------------------------------------------
void Agent::get_input(int c){ 
	direction = c;
}

int Agent::get_action(){
	return action;
}

// Moves Agent from Input
void Agent::move_agent(int x_min, int y_min, int x_max, int y_max){ // TODO- get rid of WORLD in movement function? Delete all if statmenet lines.
	switch (direction){												// ERROR when deleted ------
	case 0: // w
		if (y_agent < y_max)
		{
			++y_agent;
			++steps;
			++total_steps;
			break;
		}
		else
		{
			// error notification variable/function, will implement later
			break;
		}
	case 1: //a
		if (x_agent > x_min)
		{
			--x_agent;
			++steps;
			++total_steps;
			break;
		}
		else
		{
			// error notification variable/function, will implement later
			break;
		}
	case 2: //d
		if (x_agent < x_max)
		{
			++x_agent;
			++steps;
			++total_steps;
			break;
		}
		else
		{
			// error notification variable/function, will implement later
			break;
		}
	case 3: //s
		if (y_agent > y_min)
		{
			--y_agent;
			++steps;
			++total_steps;
			break;
		}
		else
		{
			// error notification variable/function, will implement later
			break;
		}
	default:
		cout << "wrong input" << endl << endl;
	}
}

void Agent::resolve(int x_min, int y_min, int x_max, int y_max){
	while (x_agent < x_min){
		x_agent++;
	}
	while (y_agent < y_min){
		y_agent++;
	}
	while (x_agent > x_max){
		x_agent--;
	}
	while (y_agent > y_max){
		y_agent--;
	}
}

// Qtable
void Agent::build_Qtable(int x_max, int y_max){
	for (int i = 0; i < ((x_max+1)*(y_max+1)); i++) {				// makes space for every state
		vector<double> action_row; // Create an empty row
		const unsigned int num_action = 4;		// TODO- random danger string ,only room for 4 actions
		for (int j = 0; j < num_action; j++) {	
			double iv = 0 + rand01() - rand01();		
			iv *= SMALL_NUM;			
			action_row.push_back(iv); // Add an element to the row
		}
		Qtable.push_back(action_row); // Add the row to the main vector
	}
}


void Agent::decide(){
	// switch statement for different policy structures

	vector<double> action_row;
	action_row = Qtable.at(state);
	int greedy_action, epsilon_action;
	greedy_action = distance(action_row.begin(), max_element(action_row.begin(), action_row.end()));
	epsilon_action = rand() % action_row.size(); 
	if (rand01() < epsilon){
		action = epsilon_action;
	}
	else {
		action = greedy_action;
	}

	// soft max
	// boltzmann
	// metropolis (probably not), 
	// monte carlo method
}

double Agent::compare(Target* pT){
	// switch statement for different reward structures

	double reward;
	int x_target = pT->getx_target();
	int y_target = pT->gety_target();

	reward = -((abs(x_target - x_agent)) + (abs(y_target - y_agent)));
	return reward;
}

void Agent::Qupdate(double r, int newstate, int oldstate){
	double Qnew;
	double Qold = Qtable.at(oldstate).at(action);

	vector<double> action_row;
	action_row = Qtable.at(newstate);
	
	double Qmax = *max_element(action_row.begin(), action_row.end());

	Qnew = Qold + alpha*(r + (gamma*Qmax) - Qold);

	Qtable.at(oldstate).at(action) = Qnew;
	// Store in an Agent variable
}

