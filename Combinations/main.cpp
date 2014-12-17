#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int>solution;
		vector<vector<int> >result;
		if(k==0)
			return result;

		int quan=pow(2.0,n);
		for(int i=0;i<quan;i++)//完全选最多有quan种，只取大小为k的各种solution
		{
			vector<int>solution;
			for(int j=0;j<n;j++)
				if(i>>j &1)//j+1被选上
					solution.push_back(j+1);
			if(solution.size()==k)
				result.push_back(solution);
		}
		return result;
    }
};