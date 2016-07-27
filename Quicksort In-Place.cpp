// https://www.hackerrank.com/challenges/quicksort3

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> arr;
void partition(int start, int end)
{
    if(start+1>end) return;
    int istart = start;    
    for(int k = start; k<end; k++)
    {
        if(arr[k]<arr[end])
        {
            int temp = arr[k];
            arr[k] = arr[istart];
            arr[istart] = temp;
            istart++;
        }
    }
    int temp = arr[end];
    arr[end] = arr[istart];
    arr[istart] = temp;
    for(int i = 0; i<arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    partition(start, istart-1);
    partition(istart+1, end);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    for(int i = 0; i<n; i++)
    {
        int t;
        cin>>t;
        arr.push_back(t);
    }
    partition(0, n-1);
    return 0;
}
