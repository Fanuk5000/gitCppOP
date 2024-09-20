/**
 * Done by: me
 * Student Name: Illya Maksemchuk
 * Student Group: 121
 * Lab 1.5
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void initRandomizer()
{
	// Seed the random number generator with the current time
	srand(time(0)); // srand(time(NULL)) could also be used
}
void coutVec(vector<int> a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << "[" << i << "]" << " ";
	}
}
int main()
{
	// Задано послідовність значень А[n]. Знайти мінімальне значення у послідовності.
	{

		int max;
		int sveIndxMinN;
		int sveIndxMin;
		int sveIndxMax;
		bool the_world = true;
		initRandomizer();
		bool checks = true;
		int n;
		cout << "Enter the length of the sequence: ";
		cin >> n;
		int p;
		cout << "Enter the num u are look for: ";
		cin >> p;

		// int *myVector = new int[5];
		vector<int> myVector;
		// Populate the array with random values
		for (int i = 0; i < n; i++)
		{
			// arr[i] = rand();
			int randomVar = (rand() % 100 - 50);
			myVector.push_back(randomVar);
		}
		int minN = 99999;
		int min = 99999;
		// cout the array
		coutVec(myVector, n);
		cout << endl;
		// calculation of the array
		for (int i = 0; i < n; i++)
		{
			if (p == myVector[i] and the_world)
			{
				cout << "The index of first " << p << " is " << i << endl;
				checks = false;
				the_world = false;
			}
			if (myVector[i] < minN and myVector[i] > 0)
			{
				minN = myVector[i];
				sveIndxMinN = i;
			}
			if (myVector[i] > max)
			{
				max = myVector[i];
				sveIndxMax = i;
			}
			if (myVector[i] < min)
			{
				min = myVector[i];
				sveIndxMin = i;
			}
		}
		if (checks)
		{
			cout << "In the massive there is no " << p << endl
				 << endl;
		}
		cout << "The minvalue that is >0 :" << minN << "[" << sveIndxMinN << "]" << endl
			 << endl;
		cout << "The min value: " << min << "[" << sveIndxMin << "]" << endl;
		cout << "The max value: " << max << "[" << sveIndxMax << "]" << endl
			 << endl;
		int backup;
		backup = myVector[sveIndxMax];
		myVector[sveIndxMax] = myVector[sveIndxMin];
		myVector[sveIndxMin] = backup;
		coutVec(myVector, n);
	}

	return 0;
}