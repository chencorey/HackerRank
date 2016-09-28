// https://www.hackerrank.com/contests/w23/challenges/gears-of-war

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T;
    cin>>T;
    for(int i = 0; i<T; i++)
    {
        int a;
        cin>>a;
        if(a%2==0) cout<<"Yes"<<endl;
        else cout<< "No"<<endl;
    }
    return 0;
}
