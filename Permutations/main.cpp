#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int> > result;
    vector<vector<int> > permute(vector<int> &num) {
		if(num.size()==0)
			return result;
		bool *choose=new bool[num.size()];
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

int main()
{
	Solution t;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	vector<vector<int> > re=t.permute(num);
	for(int i=0;i<re.size();i++)
	{
		for(int j=0;j<re[i].size();j++)
			cout<<re[i][j]<<" ";
		cout<<endl;
	}
}