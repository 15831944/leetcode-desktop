class Solution {
public:
    int searchInsert(int A[], int n, int target) {
		int left=0;
		int right=n-1;

		while(left<right)
		{
			int middle=A[(left+right)/2];
			if(target > middle)
				left = (left+right)/2+1 ;
			else if(target<middle)
				right=(left+right)/2;
			else
				return (left+right)/2;
		}
			

		if(target<=A[left])
			return left;
		else
			return left+1;
    }
};