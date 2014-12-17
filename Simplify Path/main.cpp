#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
		vector<string> st;
		int i=0;
		while(i<path.length())
		{
			string current="";
			if(path[i]=='/')
				current+=path[i];
			i++;
			while(i<path.length() && path[i]=='/')//去除多余的/
				i++;
			while(i<path.length() && path[i] !='/')
			{
				current+=path[i];
				i++;
			}

			//现在i指向新一轮的'/'了
			if(current=="/.")
				continue;
			else if(current=="/..")
			{
				if(!st.empty())
					st.pop_back();
			}
			else
			{	
				if(current!="/")
					st.push_back(current);
			}
		}
		string res="";
		if(st.size()==0)
			return "/";
		for(int i=0;i<st.size();i++)
			res+=st[i];
		return res;
    }
};

int main()
{
	Solution t;
	cout<<t.simplifyPath("/home//foo/").c_str();
}