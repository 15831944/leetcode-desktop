#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
		bool negative=false;
		int result=0;
        if(x<0)
		{
			if(x==INT_MIN)
				return 0;
			x=-x;
			negative=true;
		}
		while(x != 0)
		{
			if(result>INT_MAX/10)
				return 0;
			else if(result==INT_MAX/10 )
			{
				if(negative)
				{
					if(x%10>8)
						return 0;
				}
				else
				{
					if(x%10>7)
						return 0;
				}
			}

			result = result*10+ (x%10);
			x /= 10;
		}

		if(negative)
			return -result;
		return result;

    }
};

int main()
{
	Solution t;
	cout<<t.reverse(8463847412);//传进来的本来就是int，也有范围
	return 0;
}