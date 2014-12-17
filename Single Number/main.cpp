#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        for(int i=1;i<n;i++)
			A[0] ^= A[i];
		return A[0];//中途有相同的数取异或就为0了，消掉了，最后留下的就是唯一一个不重复的数了
		//前提是异或满足交换律和结合律,a^b^c^b^a=a^a^b^b^c=0^0^c=c
    }
};

int main()
{
	int a[]={3,4,5,3,2,1,2,4,5};
	Solution t;
	cout<<t.singleNumber(a,9);
}