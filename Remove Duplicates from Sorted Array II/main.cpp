#include <iostream>
using namespace std;

class Solution {
public:
	/*
    int removeDuplicates(int A[], int n) {
        if(n<=2)
			return n;
		
		int currentlen=n;

		int cur=0;
		int nex=1;
		while(nex<currentlen)
		{
			if(A[cur]==A[nex])
			{
				int countcu=0;
				cur++;
				nex++;
				
				//从nex开始，删除长度为countcu
				int delindex=nex;

				while(nex<currentlen && A[cur]==A[nex])
				{
					countcu++;
					cur++;
					nex++;
				}
				currentlen -=countcu;

				//从delindex开始，删除长度为countcu
				if(countcu !=0)
				{
					for(int i=delindex;i<currentlen;i++)
						A[i]=A[i+countcu];
					cur-=countcu;
					nex-=countcu;
				}
			}
			else
			{
				cur++;
				nex++;
			}
		}

		return currentlen;
    }*/
	int removeDuplicates(int A[], int n) {
		if(n<=2)
			return n;
		int currentinde=0;//新数组下标
		for(int i=0;i+2<n;i++)
		{
			if(A[i] !=A[i+2])
			{
				A[currentinde]=A[i];
				currentinde++;
			}
		}

		A[currentinde]=A[n-2];
		currentinde++;
		A[currentinde]=A[n-1];
		
		return currentinde+1;
	}

};

int main()
{
	Solution t;
	int a[]={1,1,1,1,3,3};
	int n=t.removeDuplicates(a,6);
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;

}