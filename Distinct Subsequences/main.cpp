#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

	/*tle
	int result;
    int numDistinct(string S, string T) {
        result=0;
		dfs(S,0,T,0);
		return result;
    }

	void dfs(string &s,int starts,string &t,int startt)
	{
		for(int i=starts;i<s.length();i++)
		{
			if(t[startt]==s[i])
			{
				if(startt+1==t.size())
					result++;
				else if(i+1==s.size())
					return;
				else
					dfs(s,i+1,t,startt+1);
			}
		}
		return;
	}*/


	int numDistinct(string S, string T) {
		int m=T.length();
		int n=S.length();
		//һάˢ��㲻�������Ƕ�άˢ������һ�㶼�� ��б�Ϸ�+���
		int **matrix=new int*[m+1];//��m+1�У�n+1�У���ʾmatrix[i][j],T[1...i]��S[1...j]ƥ�����
		for(int i=0;i<m+1;i++)
			matrix[i]=new int[n+1];
		for(int i=0;i<m+1;i++)
			matrix[i][0]=0;
		for(int j=0;j<n+1;j++)
			matrix[0][j]=1;

		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				matrix[i][j]=matrix[i][j-1]+((T[i-1]==S[j-1])?matrix[i-1][j-1]:0);

		return matrix[m][n];
	}
};

int main()
{
	Solution t;
	//cout<<t.numDistinct("aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbbaeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe","bddabdcae");
	cout<<t.numDistinct("rabbbit","rabbit");

}