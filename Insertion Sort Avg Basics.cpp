// InsertionSort.cpp: This one is for averaging the number of basic operations at different set sizes.
//YO MAKE SURE YOU HAVE C++ 11 TURNED ON

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
using namespace std;

const int SAMPLE_SIZE = 1000;
const int TEST_STEP = 10;
const int NUM_SETS = 10;
const int VARIANCE = 100000;

std::vector<vector<int>> createArrays(int size)
{
	std::vector<vector<int>> tests;
	for (int a = 0; a < NUM_SETS; a++)
	{
		std::vector<int> testSet;
		for (int x = 0; x < size; x++)
		{
			testSet.push_back(rand() % VARIANCE);
		}
		tests.push_back(testSet);
	}
	return tests;
}

int InsertSort(std::vector<int>& A)
{
	int numBasic = 0;
	int value;
	int j;

	for (int i = 1; i < A.size(); i++) {
		value = A[i];
		j = i - 1;
		numBasic++;
		while (j >= 0 && A[j] > value)
		{
			A[j + 1] = A[j];
			j = j - 1;
			numBasic++;
		}
		A[j + 1] = value;
	}
	return numBasic;
}

int main()
{
	ofstream out_data;
	out_data.open("../../outAvgBasics.txt");
	for (int i = 1; i <= SAMPLE_SIZE; i++)
	{
		if (i % TEST_STEP == 0)
		{
			std::vector<vector<int>> tests = createArrays(i);

			int opCount = 0;
			for (int a = 0; a < NUM_SETS; a++)
			{
				opCount = InsertSort(tests[a]) + opCount;
			}
			cout << i << "\n";
			out_data << i << "," << opCount/NUM_SETS << "\n";
		}
	}
	cout << "Complete \n";
	out_data << std::endl;

	std::system("PAUSE");
	return 0;
}


