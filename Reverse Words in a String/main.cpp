#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
		if(s.size()==0)
			return;
		//清理开始的空格
		while(s[0]==' ')
			s.erase(0,1);
		if(s.size()==0)
			return;
		//清理结束的空格
		while(s.back()==' ')
			s.pop_back();
		if(s.size()==0)
			return;

		//清理中间的连续空格
		for(int i=0;i<s.size();)
		{
			while(i<s.size() && s[i]!=' ')
				i++;

			//空格开始下标
			int start=i;
			int count=0;//计算有几个连续空格
			while(i<s.size() && s[i]==' ')
			{
				count++;
				i++;
			}
			if(count>1)
			{
				s.erase(start,count-1);
				i=i-(count-1);
			}
		}
		if(s.size()==0)
			return;
		
		int t=s.size()/2;
		char temp;
		for(int i=0;i<t;i++)
		{
			temp=s[i];
			s[i]=s[s.size()-1-i];
			s[s.size()-1-i]=temp;
		}

		int start=0;
		int sum;
		for(int i=0;i<s.size();)
		{
			while(i<s.size() && s[i]!=' ' )
				i++;
			//从start到i-1进行交换
			sum=start+i-1;
			for(int j=start;j<=sum/2;j++)
			{
				temp=s[j];
				s[j]=s[sum-j];
				s[sum-j]=temp;
			}

			start=i+1;
			i++;
		}

    }
};

int main()
{
	Solution t;
	string s("   a    b  c  ");
	t.reverseWords(s);

	cout<<s.c_str();
	return 0;
}