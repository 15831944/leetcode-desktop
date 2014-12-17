#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n==0)
			return 0;
		int currentlen=n;
		for(int i=0;i<currentlen;)
		{
			if(A[i]==elem)
			{
				A[i]=A[currentlen-1];
				currentlen--;
			}
			else
				i++;
		}
		return currentlen;
    }
};

int main()
{
	Solution t;
	int a[]={1,2,3};
	cout<<t.removeElement(a,3,3)<<endl;


	return 0;
}