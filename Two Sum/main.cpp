#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		map<int,int> hash;
		vector<int> result;
		for(int i=0;i<numbers.size();i++)
		{
			int numtofind=target-numbers[i];

			//在查找i之前的，看有没有numtofind
			if(hash.find(numtofind) != hash.end())
			{
				//找到了
				result.push_back(hash[numtofind]+1);
				result.push_back(i+1);
				return result;
			}

			//每次把当前数之前的积累到hash中
			hash[numbers[i]]=i;
		}
    }
};

int main()
{
	Solution t;
	vector<int> p;
	p.push_back(2);
	p.push_back(7);
	p.push_back(11);
	p.push_back(15);

	cout<<t.twoSum(p,9)[0]<<" "<<t.twoSum(p,9)[1]<<endl;
}