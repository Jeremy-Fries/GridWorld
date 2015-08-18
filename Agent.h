// Class Agent

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "Target.h"
#include "World.h"

using namespace std;

#ifndef AGENT_H
#define AGENT_H

class Agent{
public:
	// Variables
	char direction;
	double a1, a2, a3, a4;
	char e;

	// Default Constructor
	Agent();

	// Overload Constructor
	Agent(int, int);

	// Destructor
	~Agent();
	// ------------------------------------------------------------------------------
	double rand01(void);	
		// returns random number between 0-1
	// ------------------------------------------------------------------------------
	int getx_agent();
		// getx_agent - returns current x position of agent
	void setx_agent(int);
		// setx_agent - sets x_agent to initial x position in grid
	// ------------------------------------------------------------------------------
	int gety_agent();
		// gety_agent - returns current y position of agent
	void sety_agent(int);
		// sety_agent - sets y_agent to initial y position in grid
	// ------------------------------------------------------------------------------
	int get_episodes();
		// get_episodes - returns number of episodes (iterations) agent will run
	void set_episodes(int);
		// sets number of episodes (iteration)
	// ------------------------------------------------------------------------------
	int get_timesteps();
		// get_timesteps - returns number of timesteps (actions agent will take per episode)
	void set_timesteps(int);
		// sets number of timesteps
	// ------------------------------------------------------------------------------
	int get_steps();
	void set_steps(int);
	// ------------------------------------------------------------------------------
	int get_total_steps();
	void set_total_steps(int);
	// ------------------------------------------------------------------------------
	int get_state(); 
	void set_state(int);
	// ------------------------------------------------------------------------------
	double get_alpha();
	void set_alpha(double);
	// ------------------------------------------------------------------------------
	double get_gamma();
	void set_gamma(double);
	// ------------------------------------------------------------------------------
	double get_epsilon();
	void set_epsilon(double);
	// ------------------------------------------------------------------------------
	void get_input(int);
		// gets input from agent/policy

	int get_action();

	void move_agent(int x_min, int y_min, int x_max, int y_max);
		// Moves agent from input function

	void resolve(int x_min, int y_min, int x_max, int y_max);
		// Resolve boundary error

	void build_Qtable(int x_max, int y_max);
		// Builds action state table (Q table)

	void decide();

	double compare(Target* pT);

	void Qupdate(double r, int newstate, int oldstate);	// TODO-action later

	bool victory();
		// Victory Function: Agent has found Target
private:
	// Variables 
	int x_agent, y_agent, action, episodes, timesteps, state;
	unsigned int steps = 0;
	unsigned int total_steps = 0;
	double alpha, gamma, epsilon;
	vector< vector<double> > Qtable;
};

#endif //AGENT_H