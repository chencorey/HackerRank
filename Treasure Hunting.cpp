// https://www.hackerrank.com/contests/w23/challenges/treasure-hunting

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int intersect(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3)
{
	double s0x = x1-x0;
	double s0y = y1-y0;
	double s1x = x3-x2;
	double s1y = y3-y2;
	double det = s0x*s1y-s1x*s0y;
	if(det==0)
	{
		return 2;
	}
	double c0 = (s0x*(y0-y2)-s0y*(x0-x2))/det;
	double c1 = (s1x*(y0-y2)-s1y*(x0-x2))/det;
    cout << fixed << setprecision(12)<<c1 <<endl<<-c0;
	return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int x, y, a, b, c, d;
    cin>>x>>y>>a>>b;
    if(a*b>0)
    {
        c = -b;
        d = a;
    }
    else
    {
        c=b;
        d=-a;
    }
    int x3 = x+c, y3 = y+d;
    intersect(0, 0, a, b, x, y, x3, y3);
    return 0;
}
