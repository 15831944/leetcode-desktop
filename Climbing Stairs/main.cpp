#include <iostream>
using namespace std;

class Solution {
public:
    /*runtimeerror
	int climbStairs(int n) {
        if(n==0)
			return 0;
		else if(n==1)
			return 1;
		else if(n==2)
			return 2;

		return climbStairs(n-1)+climbStairs(n-2);
    }*/
	int climbStairs(int n)
	{
		 if(n==0)
			return 0;
		else if(n==1)
			return 1;
		else if(n==2)
			return 2;
		n-=2;
		int current=1;
		int next=2;
		int temp;
		while(n)
		{
			temp=next;
			next=current+next;
			current=temp;
			n--;
		}
		return next;
	}

};

int main()
{
	Solution s;
	cout<<s.climbStairs(44);
}