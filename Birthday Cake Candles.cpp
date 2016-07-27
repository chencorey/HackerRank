// https://www.hackerrank.com/contests/rookierank/challenges/birthday-cake-candles

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    int k;
    cin>>n;
	int currMax = 0;
	int currCount = 0;
    while(cin>>k)
    {
        if(k>currMax)
		{
			currMax = k;
			currCount = 1;
		}
		else if(k==currMax)
		{
			currCount++;
		}
    }
	cout<<currCount;
	return 0;
}
