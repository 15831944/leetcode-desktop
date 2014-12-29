#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &num) {
		int majority=num[0];
		int count=1;
		for(int i=1;i<num.size();i++)
		{
			if(count==0)
			{
				majority=num[i];
				count++;
			}
			else
			{
				if(majority==num[i])
					count++;
				else
					count--;
			}
		}
		return majority;
    }
};

int main()
{
	Solution t;
	
	return 0;
}