#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> >res;
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(),num.end());
		vector<int>solu;
		dfs(num,solu,0,target);
		return res;
    }
	void dfs(vector<int> &num,vector<int> solu,int currentindex,int target)
	{
		if(target==0)
		{
			res.push_back(solu);
			return;
		}
		else if(target<0)
			return;
		for(int i=currentindex;i<num.size();i++)
		{
			if(i>currentindex && num[i]==num[i-1])//去除重复，比如1，2，2，3，5，8，9，currentindex如果为第一个2，那么下一次就不能选择第二个2
				continue;
			solu.push_back(num[i]);
			dfs(num,solu,i+1,target-num[i]);
			solu.pop_back();
		}
	}
};

int main()
{
	vector<int> num;
	num.push_back(10);
	num.push_back(1);
	num.push_back(2);
	num.push_back(7);
	num.push_back(6);
	num.push_back(1);
	num.push_back(5);
	Solution t;
	vector<vector<int> >res=t.combinationSum2(num,8);
}