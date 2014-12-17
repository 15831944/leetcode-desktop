#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        //对于S中从小到大每个元素，考虑是否放在每个集合中
		sort(S.begin(),S.end());
		int elem_num=S.size();
		int subset_num=pow(2.0,elem_num);
		vector<vector<int> > subset_set (subset_num, vector<int>());//用空集初始化每个子集
		for(int i=0;i<elem_num;i++)//对于每一个S[i]
			for(int j=0;j<subset_num;j++)
				if(j>>i &1)
					subset_set[j].push_back(S[i]);

		return subset_set;
    }
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	vector<vector<int> > re=s.subsets(v);
	for(int i=0;i<re.size();i++)
	{
		vector<int> temp=re[i];
		for(int j=0;j<temp.size();j++)
			cout<<temp[j]<<" ";
		cout<<endl;
	}
}
