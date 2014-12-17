#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		int *a=new int[num1.length()+num2.length()];
		memset(a,0,sizeof(int)*(num1.length()+num2.length()));
		for(int i=num1.length()-1;i>=0;i--)
		{
			for(int j=num2.length()-1;j>=0;j--)
				a[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
		}

		for(int i=num1.length()+num2.length()-1;i>0;i--)
		{
			a[i-1] +=a[i]/10;
			a[i] %=10;
		}
		string result;
		int i=0;
		while(a[i]==0)
			i++;
		for(;i<num1.length()+num2.length();i++)
			result += a[i]+'0';
		delete a;
		if(result.length()==0)
			return "0";
		return result;
    }
};

int main()
{
	Solution s;
	cout<<s.multiply("25","25").c_str();
}