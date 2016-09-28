// https://www.hackerrank.com/contests/world-codesprint-7/challenges/two-characters

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    string word;
    cin>>word;
    int result = 0;
    if(word.length()==1)
    {
        cout<<0;
        return 0;
    }
    for(char a = 'a'; a<='z'; a++)
    {
        for(char b = 'a'; b<='z'; b++)
        {
            if(b==a)continue;
            int best = 0;
            bool first = true;
            for(int i = 0; i<word.length(); i++)
            {
                if(first)
                {
                    if(a==word[i])
                    {
                        first = false;
                        best++;
                    }
                    else if(b==word[i])
                    {
                        best = -1;
                        break;
                    }
                }
                else
                {
                    if(a==word[i])
                    {
                        best = -1;
                        break;
                    }
                    else if(b==word[i])
                    {
                        first = true;
                        best++;
                    }
                }
            }
            result = max(result, best);
        }
    }
    cout<<result;
    return 0;
}
