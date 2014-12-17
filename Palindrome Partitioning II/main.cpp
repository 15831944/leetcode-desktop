#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCut(string s) {
		if(s.length()<=1)
			return 0;

		int leng=s.length();
		bool ** ispalindrome=new bool*[leng];//下标i,j之间是否为palindrome
		for(int i=0;i<leng;i++)
			ispalindrome[i]=new bool[leng];
		for(int i=0;i<leng;i++)
			for(int j=0;j<leng;j++)
				ispalindrome[i][j]=false;

		for(int j=0;j<leng;j++)
			for(int i=j;i>=0;i--)//是对称矩阵
			{
				//is[i][j]看is[i+1][j-1]的情况
				if(i==j || j==i+1 && s[i]==s[j] || ispalindrome[i+1][j-1] && s[i]==s[j])
					ispalindrome[j][i]=ispalindrome[i][j]=true;
			}
		
		int *dp=new int[leng];
		for(int i=0;i<leng;i++)
		{
			if(ispalindrome[0][i])
				dp[i]=0;
			else
			{
				dp[i]=dp[i-1]+1;
				for(int k=i;k>=1;k--)
				{
					if(ispalindrome[k][i])
						dp[i]=min(dp[i],dp[k-1]+1);
				}
			}
		}
		return dp[leng-1];
    }
};

int main()
{
	Solution t;
	cout<<t.minCut("ab");
	return 0;
}