#include <iostream>

using namespace std;
bool checkLV(string &line)
{
	bool exist = 0;
	int n = line.length();
	if (n == 0)
		return false;
	for (int i = 0; i < n; i++)
	{

		char c = line[i];
		if (c == '.')
			exist = 1;
		if ((!(c >= 'A' and c <= 'K') and c != '.'))
			return false;
	}
	if (exist == 0)
		return false;
	return true;
}
int main()
{
	string line;
	cout << "Enter your line: ";
	cin >> line;
	bool lV = checkLV(line);
	cout << lV << endl;
	if (lV == true)
		cout << "The line belongs to L(V)" << endl;
	else
		cout << "The line doesn`t belong to L(V)" << endl;
}