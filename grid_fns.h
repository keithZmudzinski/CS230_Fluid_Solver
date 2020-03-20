#ifndef __GRIDFUNCTIONS__
#define __GRIDFUNCTIONS__


#include <vector>
#include <string>
using namespace std;


/*
	inputFileName: string; name of input file to be read from
	Data format: Each row holds space seperated values for that row in toFill.
		row 0 data
		row 1 data
		...
		row n data
		---------------------------
		Ex:
		---------------------------
		1.2 1 3.4 3 23 2 ... 3 1
		3 9 9.3 8 23 0 ... 0 9
		...
		4 9.6 3 25 28 2.5 ... 3 6

	Return type: vector<float>*
*/
vector<float>* getInputData(string inputFileName);

/*
	toFill: 2D vector of floats; holds default values, needs to be initialized
	inputFileName: string; file name of the input file

	Altered by reference: toFill
	Return type: void
*/
void fillGrid(vector< vector<float> > &toFill, string inputFileName);


/*
	pressureGrid: 2D vector of floats; holds pressure values
	i: integer; index for ith row
	j: integer; index for jth column

	Return type: float
*/
float correctPGet(const vector< vector<float> > &pressureGrid, int i, int j);


/*
	horizVelocityGrid: 2D vector of floats; holds horizontal velocity components at 1/2 indices
	i: integer; index for ith row
	j: integer; index for jth column

	Return type: float
*/
float correctHVGet(const vector< vector<float> > &horizVelocityGrid, int i, int j);


/*
	verticalVelocityGrid: 2D vector of floats; holds vertical velocity components at 1/2 indices
	i: integer; index for ith row
	j: integer; index for jth column

	Return type: float
*/
float correctVVGet(const vector< vector<float> > &verticalVelocityGrid, int i, int j);


/*
	horizVelocityGrid: 2D vector of floats; holds horizontal velocity components at 1/2 indices
	i: integer; index for ith row
	j: integer; index for jth column

	Return type: float
*/
float horCenterVel(const vector< vector<float> > &horizVelocityGrid, int i, int j);


/*
	vertVelocityGrid: 2D vector of floats; holds vertical velocity components at 1/2 indices
	i: integer; index for ith row
	j: integer; index for jth column

	Return type: float
*/
float verCenterVel(const vector< vector<float> > &vertVelocityGrid, int i, int j);


/*
	horizVelocityGrid: 2D vector of floats; holds vertical horizontal components at 1/2 indices
	vertVelocityGrid: 2D vector of floats; holds vertical velocity components at 1/2 indices
	i: integer; index for ith row
	j: integer; index for jth column

	Return type: vector<float>* of size 2
*/
vector<float>* centerVel(const vector< vector<float> > &horizVelocityGrid, const vector< vector<float> > &vertVelocityGrid, int i, int j);


/*
	horizVelocityGrid: 2D vector of floats; holds vertical horizontal components at 1/2 indices
	vertVelocityGrid: 2D vector of floats; holds vertical velocity components at 1/2 indices
	i: integer; index for ith row
	j: integer; index for jth column

	Return type: vector<float>* of size 2
*/
vector<float>* rightSideVel(const vector< vector<float> > &horizVelocityGrid, const vector< vector<float> > &vertVelocityGrid, int i, int j);


/*
	horizVelocityGrid: 2D vector of floats; holds vertical horizontal components at 1/2 indices
	vertVelocityGrid: 2D vector of floats; holds vertical velocity components at 1/2 indices
	i: integer; index for ith row
	j: integer; index for jth column

	Return type: vector<float>* of size 2
*/
vector<float>* topSideVel(const vector< vector<float> > &horizVelocityGrid, const vector< vector<float> > &vertVelocityGrid, int i, int j);

void addGravity(vector< vector<float> > &vertVelocityGrid, int xDim, int yDim, float deltaT);


// Based off of repo here: https://github.com/tunabrain/incremental-fluids.git
void project(vector< vector<float> > &pressureGrid, double deltaT, int width, int height, vector<float> &rhs);

// void myProject(vector< vector<float> > &pressureGrid, double deltaT, int width, int height, vector<float> &rhs);



// Based off of repo here: https://github.com/tunabrain/incremental-fluids.git
void applyPressure(const vector< vector<float> > &pressureGrid, vector< vector<float> > &horizVelocityGrid, vector< vector<float> > &vertVelocityGrid, double deltaT, int xDim, int yDim);


// Based off of repo here: https://github.com/tunabrain/incremental-fluids.git
vector<float>* buildRHS(const vector< vector<float> > &horizVelocityGrid, const vector< vector<float> > &vertVelocityGrid, int xDim, int yDim);

#endif
