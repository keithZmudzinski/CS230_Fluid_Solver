#include "grid_fns.h"
#include "utils.h"
#include "advect.h"
#include <string>
#include <stdlib.h>
#include <iostream>

int main(int argc, char* argv[]){
/* Below is basic skeleton of a fluid solver. Each function will be implemented,
and combine to give us a simulator.*/

	string fileName = "outputVelocities.txt";
	int numFrames = 500;
	int xDim = 32;
	int yDim = 32;
	float deltaT = 1 / 30.0;
	float t;

	int initValue = 1;

	// Make sure no existing data already in save destination, save number of frames we produce.
	clearOutputFile(fileName, numFrames, xDim, yDim);

	// 1. Initialize grids with fluid
	vector< vector<float> > pressureGrid(xDim, vector<float>(yDim, initValue));
	vector< vector<float> > horizVelocityGrid(xDim+1, vector<float>(yDim, initValue));
	vector< vector<float> > vertVelocityGrid(xDim, vector<float>(yDim+1, initValue));

	fillGrid(horizVelocityGrid, "initialHorizVelocities.txt");
	fillGrid(vertVelocityGrid, "initialVertVelocities.txt");
	fillGrid(pressureGrid, "initialPressure.txt");

	// Used for updating fields ins advect function
	vector< vector<float> > updatedHorizGrid(xDim+1, vector<float>(yDim, initValue));
	vector< vector<float> > updatedVertGrid(xDim, vector<float>(yDim+1, initValue));
	vector<float> *rhs = 0;

	const float TIME_PER_FRAME = 1 / 15.0;
	for (int i = 0; i < numFrames; ++i) {
		t = 0;
		saveVelocityField(horizVelocityGrid, vertVelocityGrid, xDim, yDim, fileName);
		deltaT = 1 / 30.0;
		while (t < TIME_PER_FRAME) {
			rhs = buildRHS(horizVelocityGrid, vertVelocityGrid, xDim, yDim);
			project(pressureGrid, deltaT, xDim, yDim, *rhs);
			applyPressure(pressureGrid, horizVelocityGrid, vertVelocityGrid, deltaT, xDim, yDim);
			advect(horizVelocityGrid, vertVelocityGrid, updatedHorizGrid, updatedVertGrid, xDim, yDim, deltaT);
			delete rhs;

			horizVelocityGrid = updatedHorizGrid;
			vertVelocityGrid = updatedVertGrid;

			t = t + deltaT;
		}
	// 	save frame i
	}
	saveVelocityField(horizVelocityGrid, vertVelocityGrid, xDim, yDim, fileName);
}
