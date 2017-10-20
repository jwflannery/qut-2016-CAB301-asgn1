// InsertionSort.cpp : Functional Testing
//YO MAKE SURE YOU HAVE C++ 11 TURNED ON

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void InsertSort(std::vector<int>& A)
{
	int value;
	int j;

	for (int i = 1; i < A.size(); i++) {

		value = A[i];
		j = i - 1;

		while (j >= 0 && A[j] > value)
		{
			A[j + 1] = A[j];
			j = j - 1;
		}
		A[j + 1] = value;
	}
}

int main()
{
	ofstream out_data;
	out_data.open("../../out.txt");

	std::vector<int> testSet = { 5, 22, 9, 7, 44, 11, 7, 11, 24, 0, 0, 2, 33, 100, 14 };

	InsertSort(testSet);

	for (int i = 0; i < testSet.size(); i++)
	{
		std::cout << "  " << testSet[i];
		out_data  << testSet[i] << ", ";
	}

	std::cout << std::endl;
	out_data << std::endl;

	std::system("PAUSE");
	return 0;
}


