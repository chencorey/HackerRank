// https://www.hackerrank.com/contests/world-codesprint-7/challenges/gridland-metro

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <utility>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long rows, cols;
    int k;
    cin>>rows>>cols>>k;
    map<int, vector<pair<int, int> > > info;
    for(int i = 0; i<k; i++)
    {
        int r, c1, c2;
        cin>>r>>c1>>c2;
        pair<int, int> bounds = make_pair(c1, c2);
        if(info.find(r)==info.end())
        {
            vector<pair<int, int> > into;
            into.push_back(bounds);
            info[r] = into;
        }
        else
        {
            vector<pair<int, int> > into = info[r];
            if(bounds.second<into[0].first)
            {
                //just insert at front
                into.insert(into.begin(), bounds);
                info[r] = into;
                continue;
            }
            if(bounds.first>into[into.size()-1].second)
            {
                //insert at end
                into.push_back(bounds);
                info[r] = into;
                continue;
            }            
            int low = 0;
            int high = into.size()-1;
            while(low<into.size()&&into[low].second<bounds.first)
            {
                low++;
            }
            while(high>=0&&into[high].first>bounds.second)
            {
                high--;
            }
            pair<int, int> toAdd = make_pair(min(bounds.first, into[low].first), max(bounds.second, into[high].second));
            into.erase(into.begin()+low, into.begin()+high+1);
            into.insert(into.begin()+low, toAdd);
            info[r] = into;
        }
    }
    long long total = rows*cols;
    for(map<int, vector<pair<int, int> > >::iterator it = info.begin(); it!=info.end(); it++)
    {
        vector<pair<int, int> > eval = it->second;
        for(int i = 0; i<eval.size(); i++)
        {
            total-=(eval[i].second-eval[i].first+1);
        }
    }
    cout<<total;
    return 0;
}
