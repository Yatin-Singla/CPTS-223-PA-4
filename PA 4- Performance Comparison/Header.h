#pragma once

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

typedef struct stats
{
	int inputSequence;
	int result;
	double timeTaken;
} Stats;

void maxSubSum1(int Arr[], int size, Stats * Seq1Stats);
void maxSubSum2(int Arr[], int size, Stats * Seq2Stats);
void maxSubSum3(int Arr[], int size, Stats * Seq3Stats);
void maxSubSum4(int Arr[], int size, Stats * Seq4Stats);

//functoin which loads integers from a text file into an array and returns the pointer to the array.
int * LoadArr(FILE * infile, int size);

//functions prints the output to a file.
void Stat(Stats algorithm, FILE * outfile);