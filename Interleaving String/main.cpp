#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
   
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=s1.length()+s2.length())
			return false;
		if(s1.length()==0)
			return s2==s3;

		bool **dp=new bool*[s1.length()+1];
		for(int i=0;i<s1.length()+1;i++)
			dp[i]=new bool[s2.length()+1];
		for(int j=1;j<=s2.length();j++)
		{
			if(s2.substr(0,j)==s3.substr(0,j))
				dp[0][j]=true;
			else
				dp[0][j]=false;
		}
		for(int i=1;i<=s1.length();i++)
		{
			if(s1.substr(0,i)==s3.substr(0,i))
				dp[i][0]=true;
			else
				dp[i][0]=false;
		}
		for(int i=1;i<=s1.length();i++)
			for(int j=1;j<=s2.length();j++)
			{
				if(dp[i-1][j]&& s3[i+j-1]==s1[i-1] || dp[i][j-1] && s2[j-1]==s3[i+j-1])
					dp[i][j]=true;
				else
					dp[i][j]=false;
			}
		return dp[s1.length()][s2.length()];
    }
};

int main()
{
	Solution t;
	cout<<t.isInterleave("abcd","ef","abcdef");
	return 0;
}