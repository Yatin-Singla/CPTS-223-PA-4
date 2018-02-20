#include "Header.h"

void maxSubSum1(int Arr[], int size, Stats * Seq1Stats)
{
<<<<<<< HEAD
	clock_t start = clock();
	int maxSum = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = i; j < size; j++)
		{
			int thisSum = 0;

			for (int k = i; k <= j; k++)
			{
				thisSum += Arr[k];
			}
				
			if (thisSum > maxSum)
			{
				maxSum = thisSum;
			}
			
		}
	}
	clock_t end = clock();
	/*
	* The number of ticks elapsed during the f() function call
	* can be calculated by (end - start). The constant
	* CLOCKS_PER_SEC specifies the relation between a clock tick
	* and a second (i.e. clock ticks per second). Therefore, dividing
	* (end - start) by CLOCKS_PER_SEC will give you the elapsed
	* time in seconds.
	*/
	cout << "CPU elapsed time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;

	Seq1Stats->result =  maxSum;
	Seq1Stats->inputSequence = size;
	Seq1Stats->timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
=======
>>>>>>> master

}

void maxSubSum2(int Arr[], int size)
{

}

void maxSubSum3(int Arr[], int size)
{

}

void maxSubSum4(int Arr[], int size)
{

}

int * LoadArr(FILE * infile, int size)
{

}

void Stat(Stats algorithm, FILE * outfile)
{

}