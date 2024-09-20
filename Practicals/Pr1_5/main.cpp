/**
 * Done by:
 * Student Name: Severyn Kotyhoroshko
 * Student Group: 123
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

int main()
{
	// Задано послідовність значень А[n]. Знайти мінімальне значення у послідовності.
	{
		initRandomizer();

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
			int randomVar = (rand() % 100) - 50;
			myVector.push_back(randomVar);
		}

		// cout the array
		for (int i = 0; i < n; i++)
		{
			cout << myVector[i] << " ";
		}
		cout << endl;

		int min = myVector[0];
		for (int i = 1; i < n; i++)
		{
			if (myVector[i] < min)
			{
				min = myVector[i];
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (p == myVector[i])
			{
				cout << "The index of first " << p << " is " << i << endl;
				break;
			}
		}
		// cout << "The minimum value in the sequence is: " << min << endl;
	}

	return 0;
}