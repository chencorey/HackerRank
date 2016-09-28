// https://www.hackerrank.com/challenges/missing-numbers

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n, m;
	cin>>n;
	int arr[201];
	for(int i = 0; i<201; i++)
	{
		arr[i] = 0;
	}
	int start;
	cin>>start;
	arr[100]++;
	for(int i = 1; i<n; i++)
	{
		int t;
		cin>>t;
		arr[t+100-start]++;
	}
	cin>>m;
	for(int i = 0; i<m; i++)
	{
		int t;
		cin>>t;
		arr[t+100-start]--;
	}
	for(int i = 0; i<201; i++)
	{
		if(arr[i]<0)cout<<(i-100+start)<<" ";
	}
	return 0;
}
