#include <iostream>
using namespace std;

class Solution {
public:
	/* long long有点cheating
    int sqrt(int x) {
        if(x<=0)
			return 0;

		long long res=0;
		long long i;
		do
		{
			i=1;
			while((res+i)*(res+i) <= x)
			{
				res += i;
				i<<=1;
			}

		}while( i>1 );

		return res;
    }*/

	//二分搜索,还可以用牛顿法 f(x)=x*x-n，求解f(x)=0的x
	int sqrt(int x) {
        if(x<=1)
			return x;

		int start=0;
		int end=x;
		int mid;
		while(start<=end)
		{
			mid=(start+end)/2;
			if(mid<x/mid)
				start=mid+1;
			else if(mid>x/mid)
				end=mid-1;
			else
				return mid;
		}

		return end;
    }
};

int main()
{
	Solution t;
	cout<<t.sqrt(9);
}