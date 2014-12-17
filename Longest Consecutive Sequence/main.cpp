#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		unordered_set<int> hash;
		int max=0;
		for(vector<int>::iterator it=num.begin();it<num.end();it++)
		{
			if(hash.find(*it) == hash.end())
				hash.insert(*it);
		}
		for(unordered_set<int>::iterator it=hash.begin();it != hash.end();it++)
		{
			int temp=1;
			int cur=*it;
			//³¯+µÄ·½ÏòÕÒ
			cur++;
			while(hash.find(cur) != hash.end())
			{
				temp++;
				hash.erase(cur);
				cur++;
			}

			cur=*it;
			cur--;
			while(hash.find(cur) != hash.end())
			{
				temp++;
				hash.erase(cur);
				cur--;
			}
			if(temp>max)
				max=temp;
		}


		return max;
    }
};

int main()
{
	Solution t;
	vector<int> p;
	p.push_back(100);
	p.push_back(4);
	p.push_back(200);
	p.push_back(1);
	p.push_back(3);
	p.push_back(2);
	cout<<t.longestConsecutive(p);
	return 0;
}