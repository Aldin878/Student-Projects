#ifndef RESULTS_H
#define RESULTS_H

//*****************************************************************************************************

struct Results
{
	int numSuccesses;
	int totalCompares;
	double percSuccesses;
	double avgNumCompares;
	Results();
};

//*****************************************************************************************************

Results::Results()
{
	numSuccesses = 0;
	totalCompares = 0;
}

//*****************************************************************************************************

#endif
