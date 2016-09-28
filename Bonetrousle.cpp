// https://www.hackerrank.com/contests/world-codesprint-6/challenges/bonetrousle

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i<cases; i++)
	{
		long long n, k, b;
		cin >> n >> k >> b;
        long long maxposs = 0;
        for(long long j = k-b+1; j<=k; j++)
        {
            maxposs+=j;
            if(maxposs>n)break;
        }
		if (n>maxposs || n<((1 + b)*b) / 2) cout << -1;
		else
		{
			for (long long j = b; j>0; j--)
			{
                long long curr = 0;
                if((j-1)%2==1)
                {
                    if(n%j>j/2) curr = n/j + 1 + (j-1)/2 + 1;
                    else curr = n/j + (j-1)/2 + 1;
                }
                else
                {
                    if(n%j>0) curr = n/j + 1 + (j-1)/2;
                    else curr = n/j + (j-1)/2;
                }
				//long long curr = ceil(((double)n) / j + ((double)(j - 1) / 2));
				n -= curr;
				cout << curr;
				if (j != 1)cout << " ";
			}
		}
		if (i != cases - 1)
			cout << endl;
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}
