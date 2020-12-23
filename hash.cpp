#include "pch.h"
using namespace std;

unsigned int hash1(unsigned int value)
{
	return(value ^ 0xdeece66d);
}

void main_hash()
{
	cout << std::hex << (0) << "\n";
	cout << std::hex << hash1(-1) << "\n";

}