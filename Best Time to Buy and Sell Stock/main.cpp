#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size()<2)
			return 0;
		int min=prices[0];
		int profit=0;
		for(vector<int>::const_iterator it=prices.begin()+1;it<prices.end();++it)
		{
			if(*(it-1)<min)
				min=*(it-1);
			if(*it-min>profit)
				profit=*it-min;
		}
		return profit;
    }
};

int main()
{
	Solution t;
	vector<int> p;
	p.push_back(5);
	p.push_back(4);
	p.push_back(9);
	p.push_back(2);
	p.push_back(8);
	p.push_back(2);
	cout<<t.maxProfit(p)<<endl;
}