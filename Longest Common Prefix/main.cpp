#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		string s;
		int count;
		if(strs.size()==0)
			return s;
		if(strs.size()==1)
			return strs[0];

		bool flag=true;
		for(count=0;flag;count++)
		{
			for(int i=0;i<strs.size()-1;i++)
			{
				if(count>strs[i].length()-1 || count>strs[i+1].length()-1 || strs[i][count] != strs[i+1][count])
				{
					flag=false;
					break;
				}
			}
		}
		return strs[0].substr(0,count-1);
    }
};

int main()
{
	Solution t;
	vector<string> vc;
	vc.push_back("abd");
	vc.push_back("abasdf");
	vc.push_back("ab");
	cout<<t.longestCommonPrefix(vc);
}