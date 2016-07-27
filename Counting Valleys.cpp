// https://www.hackerrank.com/contests/rookierank/challenges/counting-valleys

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    char k;
	cin>>n;
	int height = 0;
	int result = 0;
    while(cin>>k)
    {
        if(k=='U')
		{
			height++;
			if(height==0)
			{
				result++;
			}
		}
		else
		{
			height--;
		}
    }
	cout<<result;
	return 0;
}
