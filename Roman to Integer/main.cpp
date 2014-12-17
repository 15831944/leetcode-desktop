#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result=0;
		for(int i=0;i<s.length();i++)
			result = result*10+s[i]-'0';
		return result;
    }
};

int main()
{
	Solution t;
	cout<<t.romanToInt(string("324"));
	return 0;
}