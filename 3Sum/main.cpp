#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;
		if(num.size()<3)
			return res;
		sort(num.begin(),num.end());

		for(int i=0;i<num.size()-2;i++)
		{
			if(num[i]<0)
			{
				vector<int>solu;
				solu.push_back(num[i]);
				int start=i+1;
				int end=num.size()-1;

				while(start<end)
				{
					if(num[i]+num[start]+num[end] >0)
						end--;
					else if(num[i]+num[start]+num[end]<0)
						start++;
					else
					{
						solu.push_back(num[start]);
						solu.push_back(num[end]);
						res.push_back(solu);
						break;
					}
				}
			}
			else if(num[i]==0)
			{
				if(num[i]+num[i+1]+num[i+2]==0)
				{
					vector<int>solu;
					solu.push_back(0);
					solu.push_back(0);
					solu.push_back(0);
					res.push_back(solu);
					break;
				}
				else
					break;
			}
			else
				break;
		}
		return res;
    }
};

int main()
{
	Solution t;
	vector<int> num;
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);
	num.push_back(0);

	vector<vector<int> > res=t.threeSum(num);
	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}