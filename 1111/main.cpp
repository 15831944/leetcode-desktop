#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char s[20004];
bool isxiaochu(int x,int y,int z,int nr, int nb, int ny)
{
	vector<int> biaozhun;
	biaozhun.push_back(x);
	biaozhun.push_back(y);
	biaozhun.push_back(z);
	sort(biaozhun.begin(), biaozhun.end());
	int t1 = abs(nr - nb);
	int t2 = abs(nr - ny);
	int t3 = abs(nb - ny);
	vector<int> cur;
	cur.push_back(t1);
	cur.push_back(t2);
	cur.push_back(t3);
	sort(cur.begin(), cur.end());
	for (int i = 0; i < 3; ++i)
	{
		if (biaozhun[i] != cur[i])
			return false;
	}
	return true;
}

int main()
{
	int x, y, z;
	int nr, nb, ny,result;
	
	while (cin >> x >> y >> z)
	{
		result = 0;
		nr = 0;
		nb = 0;
		ny = 0;
		cin >> s;
		for (int i = 0; s[i] != '\0'; ++i)
		{
			if (s[i] == 'R')
				nr++;
			else if (s[i] == 'B')
				nb++;
			else if (s[i] == 'Y')
				ny++;
			int temp = nr + nb + ny;
			if (temp > result)
				result = temp;
			if (isxiaochu(x, y, z, nr, nb, ny))
			{
				nr = 0;
				nb = 0;
				ny = 0;
			}

		}
		cout << result << endl;
	}


	return 0;
}