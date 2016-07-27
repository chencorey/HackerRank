// https://www.hackerrank.com/challenges/richie-rich

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    int k;
    cin >> n >> k;
    string number;
    cin >> number;
	string result = number;
	for(int i = 0; i<result.length()/2; i++)
	{
		if(result[i]!=result[result.length()-i-1])
		{
			result[i]=max(result[i], result[result.length()-i-1]);
			result[result.length()-i-1]=max(result[i], result[result.length()-i-1]);
			k--;
		}
	}
	if(k<0)
	{
		cout<<"-1";
		return 0;
	}
	int i = 0;
	while(k>0&&i<result.length()/2)
	{
		if(result[i]=='9')
		{
			i++;
			continue;
		}
		else
		{
			if(result[i]!=number[i]||result[result.length()-i-1]!=number[result.length()-i-1])
			{
				result[i] = '9';
				result[result.length()-i-1]='9';
				k--;
				i++;
			}
			else
			{
				if(k<2)
				{
					i++;
					continue;
				}
				result[i] = '9';
				result[result.length()-i-1]='9';
				k-=2;
				i++;
			}
		}
	}
	if(k>0&&result.length()%2==1)
	{
		result[result.length()/2]='9';
	}
	cout<<result;

    return 0;
}
