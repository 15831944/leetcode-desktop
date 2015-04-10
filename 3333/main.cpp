#include <iostream>
using namespace std;

int c[100002][2];
int dis[100002];
bool visited[100002];

int mydistance(int i, int j)
{
	int temp1 = abs(c[i][0] - c[j][0]);
	int temp2 = abs(c[i][1] - c[j][1]);
	if (temp1 < temp2)
		return temp1;
	else
		return temp2;
}

int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> c[i][0] >> c[i][1];
		}
		for (int i = 0; i < n; ++i)
		{
			visited[i] = false;
			dis[i] = 2147483647;
		}
		visited[0] = true;
		dis[0] = 0;
		for (int i = 0; i < n; i++)
		{
			int min = 2147483647;
			int k = 0;
			for (int j = 1; j < n; ++j)
			{
				if (!visited[j] && min>dis[j])
				{
					min = dis[j];
					k = j;
				}
			}
			visited[k] = true;
			
			for (int ii = 0; ii < n; ++ii)
			{
				if (visited[ii])
					continue;
				int temp = mydistance(k, ii);
				if (!visited[ii] && dis[ii]>dis[k] + temp)
					dis[ii] = dis[k] + temp;
			}

			
		}
		cout << dis[n - 1] << endl;
	}


	return 0;
}