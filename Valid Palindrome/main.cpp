#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int start=0;
		int end=s.length()-1;
		if(start==end)
			return true;
		int sub=abs('a'-'A');
		int cha;
		while(start < end)
		{
			while(start<end && (s[start]<'a' || s[start]>'z') &&( s[start]<'A' || s[start]>'Z') && (s[start]<'0' || s[start]>'9'))
				start++;
			while(start<end && (s[end]<'a' || s[end]>'z') &&( s[end]<'A' || s[end]>'Z') && (s[end]<'0' || s[end]>'9'))
				end--;
			if(start>=end)
				return true;

			//数字情况
			if(s[start]>='0' &&s[start]<='9')
			{
				if(s[start]==s[end])
				{
					start++;
					end--;
					continue;
				}
				else
					return false;
			}

			//是字母情况
			cha=abs(s[start]-s[end]);
			if(cha==0 || cha==sub)
			{
				start++;
				end--;
				continue;
			}
			else
				return false;
		}

		return true;
    }
};

int main()
{
	Solution t;
	cout<<t.isPalindrome("0z;z   ; 0");
	return 0;
}