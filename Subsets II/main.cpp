#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        //对于S中从小到大每个元素，考虑是否放在每个集合中
		sort(S.begin(),S.end());
		int elem_num=S.size();

		vector<int>onesolution;
		vector<vector<int> > subset_set;
		if(S.size()==0)
			return subset_set;
		subset_set.push_back(onesolution);
		for(int i=0;i<elem_num;i++)//对于每一个S[i]
		{
			int count=1;
			while(i+1<elem_num && S[i]==S[i+1])
			{
				count++;
				i++;
			}
			//S[i]这个数出现了count次，那么它的状态，比如5出现了3次，则有添加0个5，添加1个5，添加2个5和添加3个5这几个状态
			int oldsize=subset_set.size();
			for(int k=0;k<oldsize;k++)//把前面的结果拿出来，将当前数添加进去，凑成新的解
			{
				//每个集合添加count个S[i]
				vector<int>onesolution=subset_set[k];
				for(int m=1;m<=count;m++)
				{
					onesolution.push_back(S[i]);
					subset_set.push_back(onesolution);
				}
			}
			
		}

		return subset_set;
    }
};

int main()
{
	Solution t;
	vector<int > v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	vector<vector<int> > re=t.subsetsWithDup(v);
	for(int i=0;i<re.size();i++)
	{
		for(int j=0;j<re[i].size();j++)
			cout<<re[i][j]<<" ";
		cout<<endl;
	}
}