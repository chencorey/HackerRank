// https://www.hackerrank.com/contests/world-codesprint-5/challenges/camelcase

#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <queue>
using namespace std;


int main()
{
	char a;
	int count = 1;
	while (cin >> a)
	{
		if (a >= 'A'&&a<='Z')count++;
	}
	cout << count;
	return 0;
}
