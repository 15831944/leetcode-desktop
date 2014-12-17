#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		if(matrix.size()==0)
			return vector<int>();
		int rowstart=0;
		int rowend=matrix.size()-1;
		int colstart=0;
		int colend=matrix[0].size()-1;
		vector<int> res;
		while(rowstart<=rowend && colstart<=colend)
		{
			for(int j=colstart;j<=colend;j++)//左->右
				res.push_back(matrix[rowstart][j]);
			rowstart++;
			if(rowstart>rowend)//中途有不符合条件的也立马退出
				break;
			for(int i=rowstart;i<=rowend;i++)//上->下
				res.push_back(matrix[i][colend]);
			colend--;
			if(colstart>colend)
				break;
			for(int j=colend;j>=colstart;j--)//右到左
				res.push_back(matrix[rowend][j]);
			rowend--;
			if(colstart>colend)
				break;
			for(int i=rowend;i>=rowstart;i--)//下到上
				res.push_back(matrix[i][colstart]);
			colstart++;
		}
		return res;
    }
};

int main()
{
	Solution t;
	vector<int> row(1,1);
	vector<vector<int> > matrix(1,row);


	vector<int> res=t.spiralOrder(matrix);

	return 0;
}