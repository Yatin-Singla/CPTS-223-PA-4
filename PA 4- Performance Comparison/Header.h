#pragma once

#include <iostream>
#include <fstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

typedef struct stats
{
	int inputSequence;
	int result;
	double timeTaken;
} Stats;

void maxSubSum1(int Arr[], int size, Stats * Seq1Stats);
void maxSubSum2(int Arr[], int size, Stats * Seq2Stats);
//reference data structures and algorithm analysis in C++ by Mark Allen Weiss
void maxSubSum3(int Arr[], int size, Stats * Seq3Stats);
void maxSubSum4(int Arr[], int size, Stats * Seq4Stats);

//functoin which loads integers from a text file into an array and returns the pointer to the array.
int * LoadArr(FILE * infile, int size);

//functions prints the output to a file.
void Stat(Stats algorithm, FILE * outfile);

//return the address of the file to open
char * infile_address(char file_path[], int array_size, int sample);

//generates csv files
char * outfile_address(char file_path[], char * name_outfile);

//reference data structures and algorithm analysis in C++ by Mark Allen Weiss
//called by maxsubsum3
int maxSumRec(int Arr[], int left, int right);