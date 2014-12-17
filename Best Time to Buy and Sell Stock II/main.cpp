#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size()<2)
			return 0;
		int localmin;
		int result=0;
		for(int i=0;i<prices.size()-1;)
		{
			if(i+1<prices.size() && prices[i]>=prices[i+1] )
			{
				i++;
				continue;
			}
			localmin=prices[i];
			while(i+1<prices.size() && prices[i]<=prices[i+1]  )
				i++;

			result += prices[i]-localmin;
			i++;
			//localmin=prices[i];
		}
		return result;
    }
};

int main()
{
	Solution s;
	vector <int> p;
	p.push_back(5);
	p.push_back(5);
	p.push_back(4);
	p.push_back(5);
	p.push_back(5);
	p.push_back(5);
	cout<<s.maxProfit(p);
}