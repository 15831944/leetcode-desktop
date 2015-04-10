#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;
int moduletimes[100002];

int main()
{
	int t,n,m;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			moduletimes[i] = 0;
		queue<int> sq;
		int temp;
		unordered_map<int, vector<int>> signaltomodule;
		unordered_map<int, vector<int>> moduletosignal;
		for (int i = 0; i < m; ++i)
		{
			cin >> temp;
			sq.push(temp);
		}
			
		for (int i = 0; i < n; ++i)
		{
			int sign;
			cin >> sign;
			signaltomodule[sign].push_back(i);
			vector<int> sigs;
			int t;
			cin >> t;
			if (t == 0)
				continue;
			for (int jj = 0; jj < t; ++jj)
			{
				int tsig;
				cin >> tsig;
				sigs.push_back(tsig);
			}
			moduletosignal[i]=sigs;
		}

		while (!sq.empty())
		{
			int cur = sq.front();
			sq.pop();
			if (signaltomodule.find(cur) == signaltomodule.end())
				continue;
			vector<int> curmod = signaltomodule[cur];
			for (int kk = 0; kk < curmod.size(); ++kk)
			{
				int curcur = curmod[kk];
				moduletimes[curcur]++;
				vector<int> sis = moduletosignal[curcur];
				for (int i = 0; i < sis.size(); ++i)
					sq.push(sis[i]);
			}
				
		}
		for (int i = 0; i < n; ++i)
			cout << moduletimes[i] << " ";
		cout << endl;
	}

	return 0;
}