/************************************************************************************************
*	Name: Yatin Singla																			*
*	Date: 20th February 2018																	*
*	Programming Assignment 4:																	*
*	Description: comparing  the  performance  of  the  four  different algorithms 				*
*	for the maximum subsequence sum  problem.													*
*	Reference:																					*
*	A program described in	B.Stroustrup : Wrapping C++ Member Function Calls					*
*	"The C++ Report" June 2000																	*
*	http ://www.research.att.com/~bs/wrap_code.cpp												*
*************************************************************************************************/

#include "Header.h"

int main(void)
{	
	FILE * infile = NULL, * outfileMaxSubSum1 = NULL, *outfileMaxSubSum2 = NULL, *outfileMaxSubSum3 = NULL, *outfileMaxSubSum4 = NULL;
	char infile_path[140], outfile_path[140], outfile_path2[140], outfile_path3[140], outfile_path4[140];
	int * Arr = NULL;

	Stats all_sequences = { 0,0,0.0 };

	outfileMaxSubSum1 = fopen(outfile_address(outfile_path, "maxSubSum1"), "w");
	outfileMaxSubSum2 = fopen(outfile_address(outfile_path2,"maxSubSum2"), "w");
	outfileMaxSubSum3 = fopen(outfile_address(outfile_path3,"maxSubSum3"), "w");
	outfileMaxSubSum4 = fopen(outfile_address(outfile_path4,"maxSubSum4"), "w");
	fprintf(outfileMaxSubSum1, "Input Sequence, Result, Total Time Taken\n");
	fprintf(outfileMaxSubSum2, "Input Sequence, Result, Total Time Taken\n");
	fprintf(outfileMaxSubSum3, "Input Sequence, Result, Total Time Taken\n");
	fprintf(outfileMaxSubSum4, "Input Sequence, Result, Total Time Taken\n");

	//array size
	for (int arr_size = 8; arr_size < 8193; arr_size *= 2)
	{
		// 0 - 10 samples to go through 
		for (int sample = 0; sample < 10; sample++)
		{
			//input file
			infile = fopen(infile_address(infile_path, arr_size, sample), "r");
			
			//size of array
			Arr = LoadArr(infile, arr_size);

			maxSubSum1(Arr, arr_size, &all_sequences);
			Stat(all_sequences, outfileMaxSubSum1);
			maxSubSum2(Arr, arr_size, &all_sequences);
			Stat(all_sequences, outfileMaxSubSum2);
			maxSubSum3(Arr, arr_size, &all_sequences);
			Stat(all_sequences, outfileMaxSubSum3);
			maxSubSum4(Arr, arr_size, &all_sequences);
			Stat(all_sequences, outfileMaxSubSum4);

			//free the memory
			//free(Arr);
			fclose(infile);
		}
		fprintf(outfileMaxSubSum1, "\n");
		fprintf(outfileMaxSubSum2, "\n");
		fprintf(outfileMaxSubSum3, "\n");
		fprintf(outfileMaxSubSum4, "\n");
	}

	
	fclose(outfileMaxSubSum1);
	fclose(outfileMaxSubSum2);
	fclose(outfileMaxSubSum3);
	fclose(outfileMaxSubSum4);

	return 0;
}