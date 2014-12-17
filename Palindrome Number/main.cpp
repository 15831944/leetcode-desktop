#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		if(x<0)
			return false;
		else if(x==0)
			return true;
		else if(x%10==0)
			return false;
		int temp=0;
		while(x)
		{
			if(x==temp || x/10==temp)
				return true;
			temp=temp*10+x%10;
			x/=10;
		}
		return false;
    }
};

int main()
{
	Solution t;
	cout<<t.isPalindrome(10);
	return 0;
}
