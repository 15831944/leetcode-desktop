#include <iostream>
using namespace std;

/*超时
int minstep=INT_MAX;
class Solution {
public:
	void jump(int A[], int n,int current, int step)
	{
		if(step>minstep)
			return;
		if(current==n)
		{
			//刚好跳到结束
			if(minstep>step)
				minstep=step;
			return;
		}
		if(current>n)
			return;
		//在current处，可以选择跳1-A[current]步
		for(int i=1;i<=A[current];i++)
			jump(A,n,current+i,step+1);
	}


    int jump(int A[], int n) {
		jump(A,n,0,0);
		return minstep;
    }
};
*/

/*递归超时
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
		if(!flag)//此路无法继续往回走
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
			if(step>0)//每跳一步都把step更新为最大
			{
				step--;//从i-1跳到i了，此时如果A[i]更大，则补充step，贪心思想
				step=max(step,A[i]);
			}
			else//已然跳不过来了
				return false;
		}
		//结束循环，说明跳到最后
		return true;
    }
};

int main()
{
	Solution t;
	int a[]={3,2,1,0,4};
	cout<<t.canJump(a,5);
}