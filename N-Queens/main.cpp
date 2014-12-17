#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//�ᡢ�����Խ��߶�������
class Solution {
public:
    vector<vector<string> > result;
	bool **matrix;
	vector<vector<string> > solveNQueens(int n){
		string chushi;
		for(int i=0;i<n;i++)
			chushi.append(".");

		vector<string>solution;
		for(int i=0;i<n;i++)
			solution.push_back(chushi);

		matrix=new bool*[n];
		for(int i=0;i<n;i++)
			matrix[i]=new bool[n];


		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				matrix[i][j]=false;

		dfs(solution,n,0);

		return result;
	}

	//һ��һ����solu����ӣ��Ѿ�����colu��
	void dfs(vector<string> solution,int n,int colu)
	{
		if(colu==n)
		{
			result.push_back(solution);
			return;
		}

		for(int i=0;i<n;i++)
		{
			if(matrix[i][colu])
				continue;

			//��0�е�Qռ�õ�i��
			solution[i][colu]='Q';

			//����ǰһ״̬
			bool **temp=new bool*[n];
			for(int i=0;i<n;i++)
				temp[i]=new bool[n];
			for(int qq=0;qq<n;qq++)
				for(int ww=0;ww<n;ww++)
					temp[qq][ww]=matrix[qq][ww];

			for(int y=colu+1;y<n;y++)
				matrix[i][y]=true;
			for(int x=i-1,y=colu+1;x>=0 && y<n;x--,y++)
				matrix[x][y]=true;
			for(int x=i+1,y=colu+1;x<n && y<n;x++,y++)
				matrix[x][y]=true;

			dfs(solution,n,colu+1);

			//����
			solution[i][colu]='.';
			for(int qq=0;qq<n;qq++)
				for(int ww=0;ww<n;ww++)
					matrix[qq][ww]=temp[qq][ww];

		}
	}
};

int main()
{
	Solution t;
	vector<vector<string> > re=t.solveNQueens(9);
	cout<<re.size()<<endl;
	//for(int i=0;i<re.size();i++)
	//{
	//	for(int j=0;j<re[i].size();j++)
	//		cout<<re[i][j].c_str()<<endl;
	//	cout<<endl;
	//}
}