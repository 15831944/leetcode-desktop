#include <iostream>
using namespace std;

class Solution {
public:
    void sortColors(int A[], int n) {
        int c0=0;
		int c1=0;
		int c2=0;

		int start=0;
		while( )
		{
			if(A[start]==0)
			{
				c0++;
				A[c0-1]=0;
				start++;
			}

			else if(A[start]==1)
			{
				c1++;
				start++;
			}
			else if(A[start]==2)
			{
				c2++;
				switch(A[n-c2])
				{
				case 0:
					c0++;break;
				case 1:
					c1++;break;
				case 2:
					c2++;break;
				}
				A[n-c2]=2;
				start++
			}

		}
    }
};