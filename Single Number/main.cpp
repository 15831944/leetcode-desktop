#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        for(int i=1;i<n;i++)
			A[0] ^= A[i];
		return A[0];//��;����ͬ����ȡ����Ϊ0�ˣ������ˣ�������µľ���Ψһһ�����ظ�������
		//ǰ����������㽻���ɺͽ����,a^b^c^b^a=a^a^b^b^c=0^0^c=c
    }
};

int main()
{
	int a[]={3,4,5,3,2,1,2,4,5};
	Solution t;
	cout<<t.singleNumber(a,9);
}