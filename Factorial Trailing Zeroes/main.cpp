#include <iostream>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;//把1到n中所有数分解质因数，统计5个个数就是尾号0的个数，因为2的个数肯定大于5个数
		//分开看这个循环，第一次循环，把至少含有1个5的乘数找了出来
		//比如n=31，31/5=6，即5，10，15，20，25，30这6个数的质因数至少有1个5
		//第二趟循环时，i变成6，6即把所有数往小缩，6/5=1，其实就是25这个数有2个质因数5
		for (int i = n; i > 0; i /= 5)
			res += (i / 5);
		return res;
	}
};

int main()
{
	Solution t;
	cout << t.trailingZeroes(5);

}