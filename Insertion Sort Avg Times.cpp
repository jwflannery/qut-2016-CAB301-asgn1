// InsertionSort.cpp : This one is for counting the basic operations on a bunch of random sets.
//YO MAKE SURE YOU HAVE C++ 11 TURNED ON

#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
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
	std::clock_t startTime;
	ofstream out_data;
	out_data.open("../../outTimeBasic.txt");

	for (int i = 1; i <= SAMPLE_SIZE; i++)
	{
		if (i % TEST_STEP == 0)
		{
			std::vector<vector<int>> tests = createArrays(i);
			double endTime = 0;
			double avgTime = 0;

			for (int a = 0; a < NUM_SETS; a++)
			{
				startTime = std::clock();
				InsertSort(tests[a]);
				endTime = std::clock();
				avgTime += endTime - startTime;
			}

			cout << i << "\n";
			out_data << i << ", " << avgTime/NUM_SETS << "\n";
		}
	}
	cout << "Complete \n";
	out_data << std::endl;

	std::system("PAUSE");
	return 0;
}


