#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
	int count;
	string result;
	void myswap(char &a,char &b)
	{
		char temp=a;
		a=b;
		b=temp;
	}

	void dfs(char a[],int current,int n,int k)//下标为current n之间
	{
		if(current==n)
		{
			count++;
			if(count==k)
			{
				a[n+1]='\0';
				//cout<<a<<endl;
				result=a;
				return;
			}
			return;
		}
		else
		{
			dfs(a,current+1,n,k);
			for(int j=current+1;j<=n;j++)
			{
				myswap(a[current],a[j]);
				dfs(a,current+1,n,k);
				myswap(a[current],a[j]);
			}
		}
	}

    string getPermutation(int n, int k) {
		char a[]={'1','2','3','4','5','6','7','8','9'};
		count=0;
		dfs(a,0,n-1,k);
		return result;
    }
};
*/

/*
方法二：数学解法

在n!个排列中，第一位的元素总是(n-1)!一组出现的，也就说如果p = k / (n-1)!，那么排列的最开始一个元素一定是nums[p]。

假设有n个元素，第K个permutation是
a1, a2, a3, .....   ..., an
那么a1是哪一个数字呢？
那么这里，我们把a1去掉，那么剩下的permutation为
a2, a3, .... .... an, 共计n-1个元素。 n-1个元素共有(n-1)!组排列，那么这里就可以知道
设变量K1 = K
a1 = K1 / (n-1)!
同理，a2的值可以推导为
a2 = K2 / (n-2)!
K2 = K1 % (n-1)!
 .......
a(n-1) = K(n-1) / 1!
K(n-1) = K(n-2) /2!
an = K(n-1)
*/

class Solution {
public:
	int count;
	int targetcount;
	string result;

	string getPermutation(int n, int k) {  
		string s="123456789";
		if(k<1)
			return "";
		string target=s.substr(0,n);
		count=0;
		targetcount=k;

		dfs(target,0);
		return result;
    }  

	void dfs(string &s,int start)
	{
		if(start==s.length()-1)
		{
			count++;
			if(count==targetcount)
				result=s;
		}
		for(int i=start;i<s.length();i++)
		{
			//把s[i]冒泡到s[start]
			int temp=s[i];
			for(int k=i;k>start;k--)
				s[k]=s[k-1];
			s[start]=temp;

			dfs(s,start+1);
			
			//回溯
			for(int k=start;k<i;k++)
				s[k]=s[k+1];
			s[i]=temp;
		}
	}

};


int main()
{
	Solution t;
	//string s="1234";
	//t.dfs(s,0);
	cout<<t.getPermutation(9,219601).c_str();
}