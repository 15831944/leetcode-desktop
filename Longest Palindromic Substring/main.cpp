#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int size=s.length();
		if(size==0)
			return "";
		string longest="";
		int maxlength=0;
		for(int index=0;index<size;index++)
		{
			//以index为轴向两边扩，maxlength为奇
			int start1=index-1;
			int start2=index+1;
			int currentlength=1;
			while(start1>=0 && start2<size && s[start1]==s[start2])
			{
				currentlength += 2;
				start1--;
				start2++;
			}
			if(currentlength>maxlength)
			{
				maxlength=currentlength;
				//最长的是start1+1到start2-1
				longest=s.substr(start1+1,start2-1-start1);
			}

			//以index,index+1开始比，maxlength为偶
			start1=index;
			start2=index+1;
			currentlength=0;
			while(start1>=0 && start2<size && s[start1]==s[start2])
			{
				currentlength += 2;
				start1--;
				start2++;
			}
			if(currentlength>maxlength)
			{
				maxlength=currentlength;
				//最长的是start1+1到start2-1
				longest=s.substr(start1+1,start2-1-start1);
			}
		}

		return longest;
    }
};

int main()
{
	Solution t;
	cout<<t.longestPalindrome("cabba").c_str();
	return 0;
}