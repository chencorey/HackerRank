// https://www.hackerrank.com/contests/world-codesprint-6/challenges/abbr

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string word, target;
bool go(int a, int b)
{
	if (b >= target.length())
	{
		for (int i = a; i < word.length(); i++)
		{
			if (word[i] >= 'A'&&word[i] <= 'Z')return false;
		}
		return true;
	}
	else
	{
		for (int i = a; i<word.length(); i++)
		{
			if (word[i] == target[b]) return go(i + 1, b + 1);
			if (word[i] >= 'A'&&word[i] <= 'Z') return false;
			if (toupper(word[i]) == target[b])
			{
				bool check = go(i + 1, b + 1);
				if (check)return true;
			}
		}
	}
	return false;
}
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i<cases; i++)
	{
		cin >> word;
		cin >> target;
		bool result = go(0, 0);
		if (result)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
