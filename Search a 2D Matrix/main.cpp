#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int rowsum=matrix.size();
		if(rowsum==0)
			return false;
		int columnsum=matrix[0].size();
		if(columnsum==0)
			return false;
		int rowstart=0;
		int rowend=rowsum-1;
		int mid;
		while(rowstart<rowend)
		{
			mid=(rowstart+rowend)/2;
			if(target<matrix[mid][0])
				rowend=mid;
			else if(target>matrix[mid][0])
				rowstart=mid+1;
			else
				return true;
		}
		if(rowstart==0)
		{
			if(target<matrix[rowstart][0])
				return false;
		}
		else
		{
			if(target<matrix[rowstart][0])
				rowstart--;
			else if(target==matrix[rowstart][0])
				return true;
		}

		//确定在rowstart行
		if(target<matrix[rowstart][0])
			return false;
		else if(target>matrix[rowstart][0])
		{
			//在行里做二分
			int startcol=0;
			int endcol=matrix[rowstart].size()-1;
			while(startcol<endcol)
			{
				mid=(startcol+endcol)/2;
				if(target<matrix[rowstart][mid])
					endcol=mid;
				else if(target>matrix[rowstart][mid])
					startcol=mid+1;
				else
					return true;
			}
			if(target==matrix[rowstart][startcol])
				return true;
			else
				return false;
		}
		else
			return true;
		
    }
};

int main()
{
	Solution t;
	vector<vector<int>>ma;
	vector<int>row1;
	vector<int>row2;
	vector<int>row3;
	row1.push_back(1);
	row2.push_back(3);
	row3.push_back(5);
	ma.push_back(row1);
	ma.push_back(row2);
	//ma.push_back(row3);
	cout<<t.searchMatrix(ma,3);
}