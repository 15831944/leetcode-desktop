#include <iostream>
#include <vector>
#include <string>
using namespace std;

int eliminate(string & s)
{
	vector<char> beforeeli;
	for (int i = 0; i < s.length(); ++i)
		beforeeli.push_back(s[i]);

	while (true)
	{
		vector<char> aftereli;
		for (int i = 0; i < beforeeli.size();)
		{
			if (aftereli.size() == 0)
			{
				aftereli.push_back(beforeeli[i]);
				++i;
			}
			else if (beforeeli[i] == aftereli.back())
			{
				while (i<beforeeli.size() && beforeeli[i] == aftereli.back())
					++i;
				aftereli.pop_back();
			}
			else
			{
				aftereli.push_back(beforeeli[i]);
				++i;
			}
		}
		if (aftereli.size() == beforeeli.size())
			break;
		beforeeli = aftereli;
	}
	return s.length() - beforeeli.size();
}

int main()
{
	int n;
	cin >> n;
	string old;
	string addc;
	while (n--)
	{
		cin >> old;
		int result = 0;
		for (int i = 0; i < old.length(); ++i)
		{
			addc = old;
			addc.insert(i + 1, 1,old[i]);
			int temp = eliminate(addc);
			if (temp>result)
				result = temp;
		}
		cout << result << endl;
	}
	return 0;
}