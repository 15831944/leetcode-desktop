#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> res;
    vector<string> letterCombinations(string digits) {
		if(digits.size()==0)
		{
			res.push_back("");
			return res;
		}
		string numtostr[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		string solu;
		dfs(solu,numtostr,digits,0);

		return res;
	}

	void dfs(string solu, string *numtostr,string &digits,int currentnum)//第0个数字
	{
		if(currentnum==digits.size())
		{
			res.push_back(solu);
			return;
		}

		string s=numtostr[digits[currentnum]-'0'];
		for(int j=0;j<s.size();j++)//分别取第j个字母
		{
			solu += s[j];
			dfs(solu,numtostr,digits,currentnum+1);
			solu.pop_back();
		}

	}

};

int main()
{
	Solution t;
	vector <string>res=t.letterCombinations("23");
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i].c_str()<<endl;	
	}
}