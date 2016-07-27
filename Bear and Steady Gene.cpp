// https://www.hackerrank.com/challenges/bear-and-steady-gene

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
    string dna;
	cin >> n >> dna;
	map<char, int> dict;
	dict['A'] = 0;
	dict['C'] = 1;
	dict['G'] = 2;
	dict['T'] = 3;
    int a[4];
	int curr[4];
	for(int i = 0; i<4; i++)
	{
		a[i] = 0;
		curr[i] = 0;
	}
	for(int i = 0; i<dna.length(); i++)
	{
		a[dict[dna[i]]]++;
	}
	vector<int> imp;
	for(int i = 0; i<4; i++)
	{
		a[i]-=n/4;
		if(a[i]>0) imp.push_back(i);
	}
	if(imp.size()==0)
	{
		cout<<"0";
		return 0;
	}
	int ind1 = -1;
	int ind2 = -1;
	int result = dna.length();	
	while(true)
	{
		if(ind1!=-1)
		{
			curr[dict[dna[ind1]]]--;
		}
		ind1++;
		bool works = false;
		while(!works&&ind2<(int)dna.length())
		{
			works = true;
			if(ind2<ind1) 
			{
				ind2++;
				curr[dict[dna[ind2]]]++;
			}			
			for(int i = 0; i<imp.size(); i++)
			{
				works = works && curr[imp[i]]>=a[imp[i]];
			}
			if(!works)
			{
				ind2++;
				curr[dict[dna[ind2]]]++;
			}
		}
		if(!works) break;
		result = min(result, ind2-ind1+1);
	}
	cout<<result;
    return 0;
}
