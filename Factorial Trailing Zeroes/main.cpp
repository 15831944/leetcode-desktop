#include <iostream>
using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		int res = 0;//��1��n���������ֽ���������ͳ��5����������β��0�ĸ�������Ϊ2�ĸ����϶�����5����
		//�ֿ������ѭ������һ��ѭ���������ٺ���1��5�ĳ������˳���
		//����n=31��31/5=6����5��10��15��20��25��30��6������������������1��5
		//�ڶ���ѭ��ʱ��i���6��6������������С����6/5=1����ʵ����25�������2��������5
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