#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int binarysearch(int A[],int target,int start,int end)
	{
		if(start==end && A[start] != target)
			return -1;
		int index=(start+end)/2;
		if(A[index]<target)
			return binarysearch(A,target,index+1,end);
		else if(A[index]>target)
			return binarysearch(A,target,start,index);
		else
			return index;
	}

    vector<int> searchRange(int A[], int n, int target) {
		vector<int> result;
        int index=binarysearch(A,target,0,n-1);
		if(-1==index)
		{
			result.push_back(-1);
			result.push_back(-1);
			return result;
		}
		else
		{
			int start=index;
			int end=index;
			while(start>=0 && A[start] == target )
				start--;
			while(end<n && A[end] == target)
				end++;
			result.push_back(start+1);
			result.push_back(end-1);
			return result;
		}
    }
};

int main()
{
	Solution t;
	int a[]={1};
	vector<int> p=t.searchRange(a,1,1);
	
	cout<<p[0]<<endl;
	cout<<p[1]<<endl;
}