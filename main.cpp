
#include <iostream>
#include <iomanip>
#include "SortAll.h";
using namespace std;

int main()
{
	const int arraySize = 8;
	int a[arraySize] = { 9,2,7,3,4,6,1,4};
	//int a[arraySize] = { 1,9,5,7,6,9,8,3};
	//int &rea = a;
	cout << "Data items in original order\n";
	for (int i = 0; i < arraySize; i++)
	{
		cout << setw(4) << a[i];
	}

	//BubbleSort(a, arraySize);
	//SelectSort(a, arraySize);
	//InsertSort(a, arraySize);
	//shellSort2(a, arraySize);
	//headSort(a, arraySize);
	//mergeSort1(a, arraySize);
	quickSort(a, arraySize);
	cout << "\nData items in correct order\n";
	for (int i = 0; i < arraySize; i++)
	{
		cout << setw(4) << a[i];
	}
	return 0;
}











