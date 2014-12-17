#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<string> r;
	char s[200];

	void dfs(int leftsum,int rightsum,int n)
	{
		if(rightsum==leftsum && rightsum==n)
		{
			s[2*n]='\0';
			string temp=s;
			r.push_back(temp);
			return;
		}

		else if(leftsum>rightsum && leftsum+rightsum < 2*n)//��ǰ�����Ŵ���������ʱ���ɼ�( ��)
		{
			s[leftsum+rightsum]='(';
			dfs(leftsum+1,rightsum,n);
			s[leftsum+rightsum]=')';
			dfs(leftsum,rightsum+1,n);
		}
		else if(leftsum==rightsum && leftsum < n)//��ǰ��������ʱ��ֻ���ټ�(
		{
			s[leftsum+rightsum]='(';
			dfs(leftsum+1,rightsum,n);
		}
	}

	vector<string> generateParenthesis(int n) {
		dfs(0,0,n);
		return r;
    }
};

int main()
{
	Solution t;
	vector<string> r=t.generateParenthesis(3);
	for(int i=0;i<r.size();i++)
		cout<<r[i].c_str()<<endl;

	return 0;
}