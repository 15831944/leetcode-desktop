#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		if(gas.size()==0)
			return -1;

		int size=gas.size();
		int start=0;
		int currentoil=0;
		for(int i=start;;)
		{
			if(i==size)
				i=0;
			if(start==size)
				return -1;

			currentoil=currentoil+gas[i]-cost[i];
			if((i+1)%size==start && currentoil>=0)
				return start;

			if(currentoil<0)
			{
				while(currentoil<0 && start<=i)
				{
					currentoil-=gas[start]-cost[start];
					start++;
				}
				//再从新的start出发
				i=start;
			}
			else
				i++;
		}
    }
};

int main()
{
	vector<int>gas;
	gas.push_back(1);
	gas.push_back(2);

	vector<int>cost;
	cost.push_back(2);
	cost.push_back(1);

	Solution t;
	cout<<t.canCompleteCircuit(gas,cost);
}