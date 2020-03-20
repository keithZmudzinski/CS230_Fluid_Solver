#ifndef __UTILS__
#define __UTILS__


#include <string>
#include <vector>
using namespace std;

/*
	fileName: string; name of file to clear and save info in
	numFrames: int; number of matrices -1 we'll have
	xDims: int; number of rows
	yDims: int; number of cols
	Return type: void
*/
void clearOutputFile(string fileName, int numFrames, int xDim, int yDim);


/*
	vec: vector of floats by reference; the vector to be output

	Return type: string
*/
string outputVector(vector<float> &vec);


/*
	horizVelocityGrid: 2D vector of floats; holds vertical horizontal components at 1/2 indices
	vertVelocityGrid: 2D vector of floats; holds vertical velocity components at 1/2 indices
	xDim: int; number of cells in x direction
	yDim: int; number of cells in y direction
	fileName: string; the file to output to

	Return type: void
*/
void saveVelocityField(vector< vector<float> > &horizVelocityGrid, vector< vector<float> > &vertVelocityGrid, int xDim, int yDim, string fileName);


/*
input: vector of floats; vector for which to calc magnitude

Return type: float
*/
float magnitude(vector<float> &input);

#endif
