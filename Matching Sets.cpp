// https://www.hackerrank.com/contests/w22/challenges/box-moving

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    vector<long long> x;
    vector<long long> y;
    long long smaller = 0;
    long long greater = 0;
    for(int i = 0; i<n; i++)
    {
        long long t;
        cin>>t;
        x.push_back(t);
    }
    for(int i = 0; i<n; i++)
    {
        long long t;
        cin>>t;
        y.push_back(t);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for(int i = 0; i<n; i++)
    {
        if(x[i]<y[i])
        {
            smaller+=y[i]-x[i];
        }
        else
        {
            greater+=x[i]-y[i];
        }
    }
    if(smaller!=greater)cout<<-1;
    else cout<<greater;
    return 0;
}
