// https://www.hackerrank.com/contests/w23/challenges/commuting-strings

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string input;
    int m;
    cin>>input>>m;
    int k = 1;
    int patternLength = input.length();
    int temp = input.length();
    while(k<=temp)
    {
        if(input.length()%k!=0)
        {
            k++;
            continue;
        }
        string target = input.substr(0, k);
        int i = 1;
        bool valid = true;
        while(k*i<input.length()&& valid)
        {
            valid = target == input.substr(k*i, k);
            i++;
        }
        if(!valid)
        {
            k++;
            continue;
        }
        else
        {
            patternLength = k;
            break;
        }
    }
    cout<<(m/patternLength)%1000000007;
    return 0;
}
