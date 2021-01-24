#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

//*******************************************************************************************************

class NumberArray
{
private:
	double *arrayPtr;
	int size;
public:
	NumberArray(int input = 5);
	~NumberArray();
	void setCell(int, double);
	double getCell(int) const;
	double getAverage() const;
	double getHighest() const;
	void display() const;
	void sort();
};

#endif

//*******************************************************************************************************
