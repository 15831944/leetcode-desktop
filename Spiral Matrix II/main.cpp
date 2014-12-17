#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if(n<1)
			return vector<vector<int>>();
		vector<vector<int>> res(n,vector<int>(n,0));
		int rowstart=0;
		int rowend=n-1;
		int colstart=0;
		int colend=n-1;
		int value=1;
		while(rowstart<=rowend && colstart<=colend)
		{
			for(int j=colstart;j<=colend;j++)//左->右
				res[rowstart][j]=value++;
			rowstart++;
			if(rowstart>rowend)//中途有不符合条件的也立马退出
				break;
			for(int i=rowstart;i<=rowend;i++)//上->下
				res[i][colend]=value++;
			colend--;
			if(colstart>colend)
				break;
			for(int j=colend;j>=colstart;j--)//右到左
				res[rowend][j]=value++;
			rowend--;
			if(colstart>colend)
				break;
			for(int i=rowend;i>=rowstart;i--)//下到上
				res[i][colstart]=value++;
			colstart++;
		}
		return res;
    }
};

int main()
{
	Solution t;
	vector<vector<int> > res=t.generateMatrix(2);

}