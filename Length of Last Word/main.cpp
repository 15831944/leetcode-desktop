#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        if(s==NULL)
			return 0;
		int i=0;
		for(;s[i]!='\0';i++)
			;

		if(i==0)
			return 0;

		int j;
		for(j=i-1;s[j]==' ';j--)
			;
		int count=0;
		for(int k=j;s[k]!=' ' && k>=0;k--)
			count++;
		return count;
    }
};

int main()
{
	Solution t;
	cout<<t.lengthOfLastWord("a");
	return 0;
}