#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		vector<char> st;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='(' || s[i]=='[' || s[i]=='{')
				st.push_back(s[i]);
			else if(s[i]==')')
			{
				if(st.empty() || st.back() !='(')
					return false;
				else
				{
					st.pop_back();
					continue;
				}
			}
			else if(s[i]==']')
			{
				if(st.empty() || st.back() !='[')
					return false;
				else
				{
					st.pop_back();
					continue;
				}
			}
			else if(s[i]=='}')
			{
				if(st.empty() || st.back() !='{')
					return false;
				else
				{
					st.pop_back();
					continue;
				}
			}

		}

		if(st.empty())
			return true;
		else
			return false;
    }
};

int main()
{
	Solution t;
	cout<<t.isValid("");
	return 0;
}