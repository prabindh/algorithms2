#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

/*
Create 2D array  (row of each number in set, and columns from 0 to SUM. 
Each i,j represent true if - a sum in col.j is made by subset of numbers from 0 to row.i
For each ij,
  If sum < currentnumber, then current number doesnt contribute, so use previous row as-is for this row also
  If sum == currentnumber, then mark that cell true
  If sum > currentnumber, use cell[i][j-currentnumber], as we need exact sum. Ex if currentnum is 4, and sum is 5, then we need cell[i][5-4=1]
*/


// Returns true if there is a subset of set[] with sun equal to given sum 
bool isSubsetSum(int set[], int n, int sum)
{
	// The value of subset[i][j] will be true if there is a 
	// subset of set[0..j-1] with sum equal to i 
	vector < vector<bool>> subset(n + 1, vector<bool>(sum + 1));

	// If sum is 0, then answer is true 
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	// If sum is not 0 and set is empty, then answer is false 
	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	// Fill the subset table in botton up manner 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j] ||
				subset[i - 1][j - set[i - 1]];

			cout << "[" << i << "][" << j << "]=" << subset[i][j] << ",";
		}
		cout << endl;
	}

	/* // uncomment this code to print table
	for (int i = 0; i <= n; i++)
	{
	for (int j = 0; j <= sum; j++)
		printf ("%4d", subset[i][j]);
	printf("n");
	}*/

	return subset[n][sum];
}

// Driver program to test above function 
int testPerfectSum()
{
	int set[] = { 3, 34, 4, 12, 5, 2 };
	int sum = 9;
	int n = sizeof(set) / sizeof(set[0]);
	if (isSubsetSum(set, n, sum) == true)
		printf("Found a subset with given sum");
	else
		printf("No subset with given sum");
	return 0;
}
// This code is contributed by Arjun Tyagi. 
