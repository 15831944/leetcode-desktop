#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if(n==0)
			return 0;
		int currentlen=1;

        for(int i=1;i<n;i++)//依次找不重复的往length里边写
		{
			if(A[i]!=A[currentlen-1])
			{
				A[currentlen]=A[i];
				currentlen++;
			}
		}

		return currentlen;
    }
};

int main()
{
	Solution t;
	int a[]={1,2,2};
	cout<<t.removeDuplicates(a,2);
	return 0;
}