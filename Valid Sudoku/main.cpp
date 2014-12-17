#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        unordered_map<char,bool> charhash;
		//���м��
		for(int i=0;i<board.size();i++)
		{
			charhash.clear();
			for(int j=0;j<board[i].size();j++)
			{
				if(board[i][j]=='.')
					continue;
				if(charhash.find(board[i][j]) != charhash.end())
					return false;
				else
					charhash[board[i][j]]=true;
			}
		}

		//���м��
		for(int j=0;j<board[0].size();j++)
		{
			charhash.clear();
			for(int i=0;i<board.size();i++)
			{
				if(board[i][j]=='.')
					continue;
				if(charhash.find(board[i][j]) != charhash.end())
					return false;
				else
					charhash[board[i][j]]=true;
			}
		}

		//��С���飬һ��9��С��
		for(int xiaoge=0;xiaoge<9;xiaoge++)
		{
			int hang=xiaoge/3*3;
			int lie=xiaoge%3*3;
			charhash.clear();
			for(int i=hang;i<hang+3;i++)
				for(int j=lie;j<lie+3;j++)
				{
					if(board[i][j]=='.')
						continue;
					if(charhash.find(board[i][j]) != charhash.end())
						return false;
					else
						charhash[board[i][j]]=true;
				}
		}
			
		return true;
    }
};

int main()
{
	Solution t;
	return 0;
}