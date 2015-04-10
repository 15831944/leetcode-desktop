#include <iostream>
using namespace std;

int main()
{
	int n;
	int target;
	cin >> n >> target;
	int count = 0;
	int temp;
	bool isin = false;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		if (temp < target)
			++count;
		else if (temp == target)
			isin = true;
	}
	if (isin)
		cout << count + 1 << endl;
	else
		cout << -1 << endl;
}