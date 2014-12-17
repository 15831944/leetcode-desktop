#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if(obstacleGrid.size()<1)
			return 0;
		else if(obstacleGrid[0].size()<1)
			return 0;
		int m=obstacleGrid.size();
		int n=obstacleGrid[0].size();

		int nresult[102][102]={0};

		if(obstacleGrid[0][0]==1)
			nresult[1][1]=0;
		else
			nresult[1][1]=1;
		for(int i=2;i<=obstacleGrid.size();i++)
		{
			if(obstacleGrid[i-1][0]==1)
				nresult[i][1]=0;
			else
				nresult[i][1]=nresult[i-1][1];
		}

		for(int j=2;j<=obstacleGrid[0].size();j++)
		{
			if(obstacleGrid[0][j-1]==1)
				nresult[1][j]=0;
			else
				nresult[1][j]=nresult[1][j-1];
		}

		for(int i=2;i<=obstacleGrid.size();i++)
			for(int j=2;j<=obstacleGrid[i-1].size();j++)
			{
				if(obstacleGrid[i-1][j-1]==1)
					nresult[i][j]=0;
				else
					nresult[i][j]=nresult[i][j-1]+nresult[i-1][j];
			}

		return nresult[m][n];
    }
};