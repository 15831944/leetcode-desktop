#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
		int row=board.size();
		if(row==0)
			return;
		int col=board[0].size();
		if(col==0)
			return;

		//�ӱ�Ե�������ҵ����в��ܱ���Χ�ģ����Ϊ��N�������������еġ�O�����ض�����Χ���ѡ�O���ꡮX����Ȼ��ѡ�N���ꡮO��
		queue<pair<int,int>> mq;
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
			{
				if(board[i][j]=='O' && (i==0 || i==row-1 || j==0 || j==col-1))//��Ե���
				{
					board[i][j]='N';
					if(i>0 && board[i-1][j]=='O')//��
					{
						board[i-1][j]='N';
						mq.push(make_pair(i-1,j));
					}
					if(i<row-1 && board[i+1][j]=='O')
					{
						board[i+1][j]='N';
						mq.push(make_pair(i+1,j));
					}
					if(j<col-1 && board[i][j+1]=='O')
					{
						board[i][j+1]='N';
						mq.push(make_pair(i,j+1));
					}
					if(j>0 && board[i][j-1]=='O')
					{
						board[i][j-1]='N';
						mq.push(make_pair(i,j-1));
					}

					while(!mq.empty())
					{
						int i=mq.front().first;
						int j=mq.front().second;
						mq.pop();
						//i,j��Ҫɾ���ģ�ֱ�Ӱ�i,j�������ҽ�����
						
						if(i>0 && board[i-1][j]=='O')//��
						{
							board[i-1][j]='N';
							mq.push(make_pair(i-1,j));
						}
						if(i<row-1 && board[i+1][j]=='O')
						{
							board[i+1][j]='N';
							mq.push(make_pair(i+1,j));
						}
						if(j<col-1 && board[i][j+1]=='O')
						{
							board[i][j+1]='N';
							mq.push(make_pair(i,j+1));
						}
						if(j>0 && board[i][j-1]=='O')
						{
							board[i][j-1]='N';
							mq.push(make_pair(i,j-1));
						}
					}
				}
			}

		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(board[i][j]=='O')
					board[i][j]='X';
		for(int i=0;i<row;i++)
			for(int j=0;j<col;j++)
				if(board[i][j]=='N')
					board[i][j]='O';
    }
};

int main()
{
	Solution t;
	vector<char> v1(4,'X');
	vector<vector<char>> board;
	for(int i=0;i<4;i++)
		board.push_back(v1);

	board[1][1]='O';
	board[1][2]='O';
	board[2][2]='O';
	board[3][1]='O';

	t.solve(board);
}