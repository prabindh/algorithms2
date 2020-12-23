#include "pch.h"
#include<iostream>

using namespace std;

int main_sequence_generator()
{
	byte a = 100;

	while (a > 0) { a <<= 1; cout << (int) a << ","; };

	return 0;
}