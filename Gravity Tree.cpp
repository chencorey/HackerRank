// https://www.hackerrank.com/contests/w23/challenges/gravity-1

#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int N;
int T[100001];
//T[i] is parent of node i
int P[100001][20];
int D[100001];
long long l1SD[100001];
long long l2SD[100001];
int subtreeSize[100001];

long long l1ISD[100001];
long long l2ISD[100001];
map<int, vector<int>* > children;

int calcDepth(int node)
{
	if (node == 0)
	{
		D[0] = 0;
		return 0;
	}
	else
	{
		if(D[T[node]]==-1) D[node] = calcDepth(T[node]) + 1;
		else D[node] = D[T[node]] + 1;
		return D[node];
	}
}

void preprocess()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; (1 << j) < N; j++)
		{
			P[i][j] = -1;
		}
	}
	for (int i = 0; i < N; i++)
	{
		P[i][0] = T[i];
	}
	for (int j = 1; (1 << j) < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (P[i][j - 1] != -1) P[i][j] = P[P[i][j - 1]][j - 1];
		}
	}
}

int getLCA(int p, int q)
{
	//if p is situated on a higher level than q then swap
	if (D[p] < D[q])
	{
		int temp = p;
		p = q;
		q = temp;
	}

	//compute the value of [log(L[p)]
	int log;
	for (log = 1; (1 << log) <= D[p]; log++);
	log--;

	//find the ancestor of node p situated on the same level
	//with q using the values in P
	for (int i = log; i >= 0; i--)
		if (D[p] - (1 << i) >= D[q])
			p = P[p][i];

	if (p == q)
		return p;

	//compute LCA(p, q) using the values in P
	for (int i = log; i >= 0; i--)
		if (P[p][i] != -1 && P[p][i] != P[q][i])
			p = P[p][i], q = P[q][i];

	return T[p];
}

int getDistance(int p, int q)
{
	int LCA = getLCA(p, q);
	return (D[p] - D[LCA]) + (D[q] - D[LCA]);
}

int calcSubtreeSize(int p)
{
	if (children.find(p) == children.end())
	{
		subtreeSize[p] = 0;
		return 0;
	}
	else
	{
		int count = 0;
		for (int i = 0; i < children[p]->size(); i++)
		{
			count += calcSubtreeSize((*children[p])[i])+1;
		}
		subtreeSize[p] = count;
		return count;
	}
}

long long calcL1SD(int p)
{
	if (children.find(p) == children.end())
	{
		l1SD[p] = 0;
		return 0;
	}
	else
	{
		long long l1 = 0;
		for (int i = 0; i < children[p]->size(); i++)
		{
			l1 += calcL1SD((*children[p])[i])+(subtreeSize[(*children[p])[i]]+1);
		}
		l1SD[p] = l1;
		return l1;
	}
}

long long calcL2SD(int p)
{
	if (children.find(p) == children.end())
	{
		l2SD[p] = 0;
		return 0;
	}
	else
	{
		long long l2 = 0;
		for (int i = 0; i < children[p]->size(); i++)
		{
			l2 += 2 * l1SD[(*children[p])[i]] + calcL2SD((*children[p])[i]);
		}
		l2 += subtreeSize[p];
		l2SD[p] = l2;
		return l2;
	}
}

long long calcL1ISD(int p)
{
	if (l1ISD[p] != -1) return l1ISD[p];
	long long iL1 = calcL1ISD(T[p]) + (N - subtreeSize[p] - 1);
	iL1 += l1SD[T[p]] - l1SD[p] - (subtreeSize[p] + 1);
	l1ISD[p] = iL1;
	return iL1;
}

long long calcL2ISD(int p)
{
	if (l2ISD[p] != -1) return l2ISD[p];
	//facing up
	long long iL2 = calcL2ISD(T[p]) + (N-subtreeSize[T[p]]);
	iL2 += 2 * l1ISD[T[p]];

	//facing down other branches
	
	iL2 += l2SD[T[p]] + (subtreeSize[T[p]] - subtreeSize[p] - 1) + 2 * (l1SD[T[p]] - (l1SD[p]+subtreeSize[p]+1));
	// remove self branch
	iL2 -= l2SD[p] + subtreeSize[p] + 1 + 2 * (l1SD[p]);

	l2ISD[p] = iL2;
	return iL2;
}

int main() {
	cin >> N;
	// create tree
	T[0] = -1;
	for (int i = 1; i < N; i++)
	{
		int k;
		cin >> k;
		T[i] = k-1;
		if (children.find(k - 1) == children.end())
		{
			vector<int> *c = new vector<int>;
			c->push_back(i);
			children[k - 1] = c;
		}
		else
		{
			children[k - 1]->push_back(i);
		}
	}
	// calculate depths
	for (int i = 0; i < 100001; i++)
	{
		D[i] = -1;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (D[i] == -1)
		{
			calcDepth(i);
		}
	}
	preprocess();
	// calculate subtreeSizes
	calcSubtreeSize(0);
	// calculate SDs
	calcL1SD(0);
	calcL2SD(0);
	// calculate ISDs
	for (int i = 0; i < 100001; i++)
	{
		l1ISD[i] = -1;
		l2ISD[i] = -1;
	}
	l1ISD[0] = 0;
	l2ISD[0] = 0;
	for (int i = N - 1; i > 0; i--)
	{
		if (l1ISD[i] == -1)
		{
			calcL1ISD(i);
		}
	}
	for (int i = N - 1; i > 0; i--)
	{
		if (l2ISD[i] == -1)
		{
			calcL2ISD(i);
		}
	}

	// do queries
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int measure, turnOn;
		cin >> measure >> turnOn;
		measure--;
		turnOn--;
		long long distance = getDistance(measure, turnOn);
		if (getLCA(measure, turnOn) == turnOn)
		{
			long long result = l2SD[measure] + l2ISD[measure] - (l2ISD[turnOn] + 2 * distance*l1ISD[turnOn] + distance*distance*(N-subtreeSize[turnOn]-1));
			cout << result<< endl;
		}
		else
		{			
			long long result = l2SD[turnOn] + 2 * distance*(l1SD[turnOn]) + distance*distance*(subtreeSize[turnOn]+1);
			cout << result<< endl;
		}
	}
	return 0;
}

