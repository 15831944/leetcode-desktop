#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		if(a.length()==0)
			return b;
		if(b.length()==0)
			return a;

		int lenres=max(a.length(),b.length())+1;
		int starta=a.length()-1;
		int startb=b.length()-1;
		string result(lenres,'0');
		int startres=lenres-1;
		int jinwei=0;
		while(starta>=0 &&startb>=0)
		{
			if(a[starta]=='0' && b[startb]=='0')
			{
				if(jinwei==0)
				{
					result[startres]='0';
					jinwei=0;
				}
				else
				{
					result[startres]='1';
					jinwei=0;
				}
			}

			else if(a[starta]=='0' && b[startb]=='1')
			{
				if(jinwei==0)
				{
					result[startres]='1';
					jinwei=0;
				}
				else
				{
					result[startres]='0';
					jinwei=1;
				}
			}
			else if(a[starta]=='1' && b[startb]=='0')
			{
				if(jinwei==0)
				{
					result[startres]='1';
					jinwei=0;
				}
				else
				{
					result[startres]='0';
					jinwei=1;
				}
			}
			else if(a[starta]=='1' && b[startb]=='1')
			{
				if(jinwei==0)
				{
					result[startres]='0';
					jinwei=1;
				}
				else
				{
					result[startres]='1';
					jinwei=1;
				}
			}

			startres--;

		}

    }
};