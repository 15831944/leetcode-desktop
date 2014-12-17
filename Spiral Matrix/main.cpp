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
			for(int j=colstart;j<=colend;j++)//��->��
				res.push_back(matrix[rowstart][j]);
			rowstart++;
			if(rowstart>rowend)//��;�в�����������Ҳ�����˳�
				break;
			for(int i=rowstart;i<=rowend;i++)//��->��
				res.push_back(matrix[i][colend]);
			colend--;
			if(colstart>colend)
				break;
			for(int j=colend;j>=colstart;j--)//�ҵ���
				res.push_back(matrix[rowend][j]);
			rowend--;
			if(colstart>colend)
				break;
			for(int i=rowend;i>=rowstart;i--)//�µ���
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