#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
		//Each step you may move to adjacent numbers on the row below.
		if(triangle.size()==0)
			return 0;
		int size=triangle.size();
		int *sum=new int[triangle.size()];
		memset(sum,0,sizeof(int)*triangle.size());

		for(int i=0;i<size;i++)
			sum[i]=triangle[size-1][i];
		for(int i=triangle.size()-2;i>=0;i--)
		{
			for(int j=0;j<triangle[i].size();j++)
				sum[j]=triangle[i][j]+min(sum[j],sum[j+1]);
		}

		return sum[0];
    }
};

int main()
{}