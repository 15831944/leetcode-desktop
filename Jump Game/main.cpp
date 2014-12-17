#include <iostream>
using namespace std;

/*��ʱ
int minstep=INT_MAX;
class Solution {
public:
	void jump(int A[], int n,int current, int step)
	{
		if(step>minstep)
			return;
		if(current==n)
		{
			//�պ���������
			if(minstep>step)
				minstep=step;
			return;
		}
		if(current>n)
			return;
		//��current��������ѡ����1-A[current]��
		for(int i=1;i<=A[current];i++)
			jump(A,n,current+i,step+1);
	}


    int jump(int A[], int n) {
		jump(A,n,0,0);
		return minstep;
    }
};
*/

/*�ݹ鳬ʱ
class Solution {
public:
	
	int dp(int A[],int final)
	{
		bool flag=false;
		int min=INT_MAX;
		for(int i=0;i<final;i++)
		{
			if(i+A[i]>=final)
			{
				if(i==0)
					return 1;
				flag=true;
				int temp=dp(A,i);
				if(temp!=-1)
					if(min>temp)
						min=temp;
			}
		}
		if(!flag)//��·�޷�����������
			return -1;
		return min+1;
	}
    int jump(int A[], int n) {
		return dp(A,n);
    }
};
*/

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n<1)
			return false;
		int step=A[0];
		for(int i=1;i<n;i++)
		{
			if(step>0)//ÿ��һ������step����Ϊ���
			{
				step--;//��i-1����i�ˣ���ʱ���A[i]�����򲹳�step��̰��˼��
				step=max(step,A[i]);
			}
			else//��Ȼ����������
				return false;
		}
		//����ѭ����˵���������
		return true;
    }
};

int main()
{
	Solution t;
	int a[]={3,2,1,0,4};
	cout<<t.canJump(a,5);
}