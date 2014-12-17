#include <iostream>
using namespace std;

class Solution {
public:
	/*TLE
    int numDecodings(string s) {
		if(s.length()==0)
			return 0;
		return dfs(s,0);
    }

	int dfs(string &s, int subindexstart)
	{
		if(subindexstart==s.length()-1)
			return 1;
		else if(subindexstart==s.length()-2)
		{
			if(s[subindexstart]=='2' && s[subindexstart+1]<='6' || s[subindexstart]=='1')
				return 2;
			else
				return 1;
		}

		int num1=dfs(s,subindexstart+1);
		int num2=0;
		if(s[subindexstart]=='2' && s[subindexstart+1]<='6' || s[subindexstart]=='1')
			num2=dfs(s,subindexstart+2);
		return num1+num2;
	}*/

	int numDecodings(string s) {
		//用动态规划可以O(n)求解出来
		//a[i]代表子字符串string(0,i)的可能解码方式，
		//a[i] = {a[i-1] or a[i-1]+a[i-2]}.
		if (s.size()==0)
            return 0;
        if (s.at(0) == '0')
            return 0;
        int len = s.size();
        int* a = new int[len];
 
        a[0] = 1;
        for (int i = 1; i < len; i++)
        {
            a[i] = 0;
 
            if (s.at(i) != '0')
                a[i] = a[i - 1];
             
            if (s.at(i - 1) != '0')
            {
                int val = (s.at(i - 1) - '0') * 10 + (s.at(i) - '0');
                if (val <= 26 && val > 0)
                {
                    if (i >= 2)
                        a[i] += a[i - 2];
                    else
                        a[i] += 1;
                }
            }
 
            if (a[i] == 0)
                return 0;
        }
 
        return a[len-1];
    }
};

int main()
{
	Solution t;
	cout<<t.numDecodings("13034324")<<endl;
	return 0;
}