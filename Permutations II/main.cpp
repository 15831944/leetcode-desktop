#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > result;
    vector<vector<int> > permute(vector<int> &num) {
		if(num.size()==0)
			return result;
		bool *choose=new bool[num.size()];
		sort(num.begin(),num.end());
		memset(choose,false,sizeof(bool)*num.size());
		vector<int> solu;
		dfs(num,choose,solu);
		return result;

    }

	void dfs(vector<int> &num, bool *choose,vector<int> solu)
	{
		if(solu.size()==num.size())
		{
			result.push_back(solu);
			return;
		}
		for(int i=0;i<num.size();i++)
		{
			if(!choose[i])
			{
				solu.push_back(num[i]);
				choose[i]=true;
				dfs(num,choose,solu);
				solu.pop_back();
				choose[i]=false;
			}
		}
	}
};