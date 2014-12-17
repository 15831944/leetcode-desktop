#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution2 {
public:
    bool isScramble(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        if (l1 != l2) return false;
        if (l1 == 1) return s1 == s2;
        string st1 = s1, st2 = s2;
        sort(st1.begin(), st1.end());
        sort(st2.begin(), st2.end());
        for (int i = 0; i < l1; ++i) {
            if (st1[i] != st2[i]) {
                return false;
            }
        }
        string s11, s12, s21, s22;
        bool res = false;
        for (int i = 1; i < l1 && !res; ++i) {
            s11 = s1.substr(0, i);
            s12 = s1.substr(i, l1 - i);
            s21 = s2.substr(0, i);
            s22 = s2.substr(i, l1 - i);
            res = isScramble(s11, s21) && isScramble(s12, s22);
            if (!res) {
                s21 = s2.substr(0, l1 - i);
                s22 = s2.substr(l1 - i, i);
                res = isScramble(s11, s22) && isScramble(s12, s21);
            }
        }
        return res;
    }
};
class Solution {
public:
    bool isScramble(string s1, string s2) {
		if(s1.length()==1 && s2.length()==1)
		{
			if(s1[0]==s2[0])
				return true;
			else
				return false;
		}
		else if(s1.length()==2 && s2.length()==2)
		{
			if(s1[0]==s2[0]&&s1[1]==s2[1] || s1[0]==s2[1] && s1[1]==s2[0])
				return true;
			else
				return false;
		}
		else
		{
			string ss1=s1;
			string ss2=s2;
			sort(ss1.begin(),ss1.end());
			sort(ss2.begin(),ss2.end());
			for(int i=0;i<ss1.length();i++)
				if(ss1[i]!=ss2[i])
					return false;
			
			bool res;
			for(int i=1;i<=s1.length()-1;i++)
			{
				//为什么开新的string作为参数传递进去，比直接s1.substr(0,i)作为参数传递快这么多。。
				//能在这一层执行的不要弄到下一层执行
				string s11=s1.substr(0,i);
				string s12=s1.substr(i,s1.length()-i);
				string s21=s2.substr(0,i);
				string s22=s2.substr(i,s2.length()-i);
				
				if(isScramble(s11,s21) && isScramble(s12,s22))
					return true;
				else
				{
					s21=s2.substr(s2.length()-i,i);
					s22=s2.substr(0,s2.length()-i);
					if(isScramble(s11,s21) && isScramble(s12,s22))
						return true;
				}
			}
			return false;
		}
    }
};

int main()
{
	Solution t;
	cout<<t.isScramble("great","rgeat");
	return 0;
}