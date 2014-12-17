#include <iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
		if(s.size()==0)
			return;
		//����ʼ�Ŀո�
		while(s[0]==' ')
			s.erase(0,1);
		if(s.size()==0)
			return;
		//��������Ŀո�
		while(s.back()==' ')
			s.pop_back();
		if(s.size()==0)
			return;

		//�����м�������ո�
		for(int i=0;i<s.size();)
		{
			while(i<s.size() && s[i]!=' ')
				i++;

			//�ո�ʼ�±�
			int start=i;
			int count=0;//�����м��������ո�
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
			//��start��i-1���н���
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