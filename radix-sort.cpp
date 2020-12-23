#include "pch.h"
#include<iostream>
#include<list>
#include<cmath>
using namespace std;
void display(std::unique_ptr<int[]> &arr, int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void radixSort(std::unique_ptr<int[]> &arr, int n, int max) {
	int i, j, m, p = 1, index, temp, count = 0;
	list<int> pocket[10];      //radix of decimal number is 10
	for (i = 0; i < max; i++) {
		m = pow(10, i + 1);
		p = pow(10, i);
		for (j = 0; j < n; j++) {
			temp = arr[j] % m;
			index = temp / p;      //find index for pocket array
			pocket[index].push_back(arr[j]);
		}
		count = 0;
		for (j = 0; j < 10; j++) {
			//delete from linked lists and store to array
			while (!pocket[j].empty()) {
				arr[count] = *(pocket[j].begin());
				pocket[j].erase(pocket[j].begin());
				count++;
			}
		}
	}
}
int main_radix_sort() {
	int n, max;
	cout << "Enter the number of elements: ";
	cin >> n;
	cout << "Enter the maximum digit of elements: ";
	cin >> max;
	//const int n = 1000, int arr[n];
	//int arr[n]; //create an array with given number of elements
	//int* arr = new int[n];
	auto arr = std::make_unique<int[]>(n);
	cout << "Enter elements:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << "Data before Sorting: ";
	display(arr, n);
	radixSort(arr, n, max);
	cout << "Data after Sorting: ";
	display(arr, n);

	return 0;
}