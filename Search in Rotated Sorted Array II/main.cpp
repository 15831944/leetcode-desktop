#include <iostream>
using namespace std;
class Solution {
public:
    int search(int A[], int n, int target) {
        int left=0;
		int right=n-1;
		int mid;
		while(left<=right)
		{
			mid=(left+right)/2;
			if(target == A[mid])
				return mid;
			else if(target<A[mid] && A[left]<=A[mid])//ÒÑÈ»ÉýÐò
				right=mid-1;
			else//target>Amid »ò A[left]>A[mid]
			{
				if(A[left]>A[mid])
					;
				else
					left=mid+1;
			}
		}
		return -1;
    }
};

int main()
{
	Solution t;
	int a[7]={4,5,6 ,7, 0, 1, 2};
	cout<<t.search(a,7,0);
	return 0;
}