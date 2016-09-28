// https://www.hackerrank.com/contests/world-codesprint-6/challenges/flipping-the-matrix

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int cases;
    cin>>cases;
    for(int i =0; i<cases; i++)
    {
        long long mat[256][256];
        int n;
        cin>>n;
        for(int j = 0; j<2*n; j++)
        {
            for(int k = 0; k<2*n; k++)
            {
                cin>>mat[j][k];
            }
        }
        long long total = 0;
        for(int j = 0; j<n; j++)
        {
            for(int k = 0; k<n; k++)
            {
                total+=max(max(mat[j][k], mat[2*n-1-j][k]),max(mat[j][2*n-1-k], mat[2*n-1-j][2*n-1-k]));
            }
        }
        cout<<total<<endl;
    }    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
