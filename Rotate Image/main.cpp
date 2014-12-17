#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int n=matrix.size();
		//先沿主对角线对折，然后0列与n-1列交换，1列与n-2列交换。。。
		int temp;
		for(int i=1;i<=n-1;i++)
			for(int j=0;j<i;j++)
			{
				temp=matrix[i][j];
				matrix[i][j]=matrix[j][i];
				matrix[j][i]=temp;
			}

		for(int j=0;j<n/2;j++)//对于第j列
			for(int i=0;i<n;i++)//第j列的第i行
			{
				temp=matrix[i][j];
				matrix[i][j]=matrix[i][n-1-j];
				matrix[i][n-1-j]=temp;
			}
    }
};

int main()
{
}