#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

char string1[] = "AB\0";
char string2[] = "XY\0";

void PrintInterleaved(char* str1, char* str2)
{
	if (!*str2 && !*str1)
	{
		cout << endl;
		return;
	}
	if (*str1)
	{
		cout << str1;
		PrintInterleaved(str1 + 1, str2);
		PrintInterleaved(str2, str1 + 1);
	}
	if (*str2)
	{
		cout << str2;
		PrintInterleaved(str2 + 1, str1);
		PrintInterleaved(str1, str2 + 1);
	}
}

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int l, int r)
{
	int i;
	if (l == r)
		printf("%s\n", a);
	else
	{
		for (i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, r);
			swap((a + l), (a + i)); //backtrack 
		}
	}
}

void permute2(string str, string prefix)
{
	//cout << str.c_str() << "+" << prefix.c_str() << endl; 
	if (str.length() == 0)
	{
		cout << prefix.c_str() << endl;
	}
	else
	{
		for (int i = 0; i < str.length(); i++)
		{
			string rem = str.substr(0, i) + str.substr(i + 1);
			//cout << i << ",";
			permute2(rem, prefix + str.at(i));
		}
	}
}

int testPermuteStrings()
{
	char str[] = "ABC";
	int n = strlen(str);
	permute(str, 0, n - 1);
	return 0;
}

int testInterleaveStrings()
{
	//testPermuteStrings();
	permute2("ABCD", "");

	//PrintInterleaved(string1, string2);
	return 0;
}