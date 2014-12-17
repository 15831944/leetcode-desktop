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

	void dfs(char a[],int current,int n,int k)//�±�Ϊcurrent n֮��
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
����������ѧ�ⷨ

��n!�������У���һλ��Ԫ������(n-1)!һ����ֵģ�Ҳ��˵���p = k / (n-1)!����ô���е��ʼһ��Ԫ��һ����nums[p]��

������n��Ԫ�أ���K��permutation��
a1, a2, a3, .....   ..., an
��ôa1����һ�������أ�
��ô������ǰ�a1ȥ������ôʣ�µ�permutationΪ
a2, a3, .... .... an, ����n-1��Ԫ�ء� n-1��Ԫ�ع���(n-1)!�����У���ô����Ϳ���֪��
�����K1 = K
a1 = K1 / (n-1)!
ͬ��a2��ֵ�����Ƶ�Ϊ
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
			//��s[i]ð�ݵ�s[start]
			int temp=s[i];
			for(int k=i;k>start;k--)
				s[k]=s[k-1];
			s[start]=temp;

			dfs(s,start+1);
			
			//����
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