#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
		if(S.length()==0)
			return "";

		bool isinT[125]={false};
		int requir[125]={0};
		for(int i=0;i<T.length();i++)
		{
			isinT[T[i]]=true;
			requir[T[i]]++;
		}

		string res="";
		int curmin=INT_MAX;
        int start=-1;
		int end=0;
		int count=0;//����s�е���T�г��ָ���
		
		while(start<end)
		{
			//end���ƣ��ҵ��պ��ܹ�����T��λ��
			while(end<S.length() && count<T.length())
			{
				if(requir[T[end]]>0)
				{
					count++;
					requir[T[end]]--;
				}
				end++;
			}

			//startǰ�ƣ�ѹ��
			start++;
			while(start<end)
			{

			}
		}
		return res;
    }
};

int main()
{
	Solution t;
	cout<<t.minWindow("bba","ab").c_str();
	//cout<<(int)'z';
	return 0;
}