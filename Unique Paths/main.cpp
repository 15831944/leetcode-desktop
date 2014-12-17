#include <iostream>
using namespace std;

class Solution {
public:
	/* Time Limit Exceeded
    int uniquePaths(int m, int n) {
        if(m<=0 || n<=0)
			return 0;

		if(m==1)
			return 1;
		if(n==1)
			return 1;
		
		return uniquePaths(m,n-1)+uniquePaths(m-1,n);
    }*/
	
	int uniquePaths(int m, int n) {

		if(m<=0 || n<=0)
			return 0;
		int result[102][102]={0};
		for(int i=1;i<=100;i++)
			result[i][1]=result[1][i]=1;

		for(int i=2;i<=100;i++)
			for(int j=i;j<=100;j++)
				result[i][j]=result[j][i]=result[i][j-1]+result[i-1][j];
		return result[m][n];
	}
};

int main()
{

	return 0;
}