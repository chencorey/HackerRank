// https://www.hackerrank.com/contests/w23/challenges/lighthouse

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool arr[50][50];
int N;
bool checkValid(int X, int Y, int r)
{
	for (int i = 0; i <= r; i++)
	{
		int left = X - i;
		int right = X + i;
		int dy = sqrt(r*r - i*i);
		int low = Y - dy;
		int high = Y + dy;
        for(int j = left; j<=right; j++)
        {
            if(!arr[j][low]||!arr[j][high])return false;
        }
        for(int j = low; j<=high; j++)
        {
            if(!arr[left][j]||!arr[right][j])return false;
        }
	}
	return true;
}
int main() {
	cin >> N;
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			char c;
			cin >> c;
			arr[i][j] = (c == '.');
		}
	}
	int best = 0;
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			int k = 0;
			bool valid = true;
			while (i + k<N&&i - k >= 0 && j + k<N&&j - k >= 0 && valid)
			{
				valid = checkValid(i, j, k);
				k++;
			}
			if (!valid)k--;
			best = max(best, k - 1);
		}
	}
	cout << best;
	return 0;
}

