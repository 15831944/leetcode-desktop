#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		vector<int> validindex;
		vector<int> st;
		int i=0;
		while(i<s.length())
		{
			if(s[i]=='(')
			{
				st.push_back(i);
			}
			else
			{
				if(!st.empty())
				{
					validindex.push_back
					st.pop_back();
				}
			}
			i++;
		}
		
    }
};