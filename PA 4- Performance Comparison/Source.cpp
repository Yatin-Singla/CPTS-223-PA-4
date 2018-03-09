#include "Header.h"

void maxSubSum1(int Arr[], int size, Stats * Seq1Stats)
{
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
}

void maxSubSum2(int Arr[], int size, Stats * Seq2Stats)
{
	clock_t start = clock();
	int maxSum = 0;

	for (int i = 0; i < size; i++)
	{
		int thisSum = 0;
		for (int j = i; j < size; j++)
		{
			thisSum += Arr[j];
			if (thisSum > maxSum)
			{
				maxSum = thisSum;
			}
		}
	}
	clock_t end = clock();

	cout << "CPU elapsed time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;

	Seq2Stats->result = maxSum;
	Seq2Stats->inputSequence = size;
	Seq2Stats->timeTaken = (double)(end - start) / CLOCKS_PER_SEC;
}

/*Recursive maximum contiguous subsequence sum algorithm. Finds maximum sum in subarray spanning
a[left..right]. Does not attempt to maintain actual best sequence*/
int maxSumRec(int Arr[], int left, int right)
{
	if(left==right) //Base Case
		if (Arr[left] > 0)
		{
			return Arr[left];
		}
		else
		{
			return 0;
		}

	int center = (left + right) / 2;
	int maxLeftSum = maxSumRec(Arr, left, center);
	int maxRightSum = maxSumRec(Arr, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = center; i >= left; i--)
	{
		leftBorderSum += Arr[i];
		if (leftBorderSum > maxLeftBorderSum)
		{
			maxLeftBorderSum = leftBorderSum;
		}
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (int j = center + 1; j <= right; j++)
	{
		rightBorderSum += Arr[j];
		if (rightBorderSum > maxRightBorderSum)
		{
			maxRightBorderSum = rightBorderSum;
		}
	}
	
	if (maxLeftSum - maxRightSum > 0 && maxLeftSum - (maxLeftBorderSum + maxRightBorderSum) > 0)
	{
		return maxLeftSum;
	}
	else if (maxRightSum - maxLeftSum > 0 && maxRightSum - (maxLeftBorderSum + maxRightBorderSum) > 0)
	{
		return maxRightSum;
	}
	else
	{
		return maxLeftBorderSum + maxRightBorderSum;
	}
}
void maxSubSum3(int Arr[], int size, Stats * Seq3Stats)
{
	clock_t start = clock();
	int maxSum = maxSumRec(Arr, 0, size - 1);
	clock_t end = clock();

	cout << "CPU elapsed time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;

	Seq3Stats->result = maxSum;
	Seq3Stats->inputSequence = size;
	Seq3Stats->timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

}


void maxSubSum4(int Arr[], int size, Stats * Seq4Stats)
{
	clock_t start = clock();
	int maxSum = 0, thisSum = 0;
	for (int j = 0; j < size; j++)
	{
		thisSum += Arr[j];
		if(thisSum>maxSum)
		{
			maxSum = thisSum;
		}
		else if (thisSum < 0)
		{
			thisSum = 0;
		}
	}
	clock_t end = clock();
	cout << "CPU elapsed time in seconds: "
		<< (double)(end - start) / CLOCKS_PER_SEC << endl;

	Seq4Stats->result = maxSum;
	Seq4Stats->inputSequence = size;
	Seq4Stats->timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

}

int * LoadArr(FILE * infile, int size)
{
	int temp = 0, i = 0;
	int * Arr = (int *)calloc(size, sizeof(int));
	while (!feof(infile))
	{
		fscanf(infile, "%d", &temp);
		*(Arr + i) = temp;
		i++;
	}
	return Arr;
}

void Stat(Stats algorithm, FILE * outfile)
{
	fprintf(outfile, "%d, %d, %lf\n", algorithm.inputSequence, algorithm.result, algorithm.timeTaken);
}

char * infile_address(char file_path[], int array_size, int sample)
{
	sprintf(file_path, "E:/WSU/Semester 3/Computer Science 223/Programming Assignments/PA 4- Performance Comparison/inputs/inputs/input_%d_%d.txt", array_size, sample);

	return file_path;
}

//stores the custom made name into file_path array
char * outfile_address(char file_path[], char * name_outfile)
{
	sprintf(file_path, "Outfile/%s.csv", name_outfile);

	return file_path;
}