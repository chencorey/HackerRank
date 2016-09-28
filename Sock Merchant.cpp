// https://www.hackerrank.com/contests/world-codesprint-7/challenges/sock-merchant

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> socks;
int main() {
    int N;
    cin>>N;
    for(int i = 0; i<N; i++)
    {
        int sock;
        cin>>sock;
        int found = -1;
        for(int j = 0; j<socks.size(); j++)
        {
            if(sock==socks[j])
            {
                found = j;
                break;
            }
        }
        if(found>-1)
        {
            socks.erase(socks.begin()+found);
        }
        else
        {
            socks.push_back(sock);
        }
    }
    cout << (N-(int)socks.size())/2;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
