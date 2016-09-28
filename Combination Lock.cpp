// https://www.hackerrank.com/contests/world-codesprint-6/challenges/combination-lock

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a[5];
    int b[5];
    int cost = 0;
    for(int i = 0; i<5; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i<5; i++)
    {
        cin>>b[i];
        int c = max(a[i], b[i]);
        int d = min(a[i], b[i]);
        cost+=min(c-d, d+10-c);
    }
    cout<<cost;
    return 0;
}
