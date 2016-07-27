// https://www.hackerrank.com/contests/world-codesprint-5/challenges/string-construction

#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <queue>
using namespace std;


int main()
{
	int N;
	cin >> N;
	for (int j = 0; j < N; j++)
	{	
		int arr[26];
		for (int i = 0; i < 26; i++)
		{
			arr[i] = 0;
		}
		char a;
		cin.get(a);
		while (cin.get(a)&&a!='\n')
		{
			arr[a - 'a']++;
		}
		int count = 0;
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] > 0) count++;
		}
		cout << count << endl;
	}
	return 0;
}
