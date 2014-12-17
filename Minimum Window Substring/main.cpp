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
        int start=0;
		int end=0;
		int count=0;//����s�е���T�г��ָ���

		//�ҵ���һ����target����ֵ���ĸ
		while(start<S.length() && !isinT[S[start]] )
			start++;
		//startΪ��һ�����ֵģ��ҵ�һ����ĸ
		end=start;

		while(start<end)
		{
			while(end<S.length() && count<T.length())
			{
				if(isinT[S[end]] && requir[S[end]]>0)
				{
					requir[S[end]]--;
					count++;
				}
				else if(isinT[S[end]] && requir[S[end]]<=0)
					requir[S[end]]--;
				end++;
			}
			if(count<T.length())//end��ͷ�ˣ���countû����
				break;
			if(end-start<curmin)
			{
				curmin=end-start;
				res=S.substr(start,end-start);
			}
			//start��ǰ�ߵĻ�������ǰ��Ӧ������++
			requir[S[start]]++;
			if(requir[S[start]]>0)//�������Ϊ������count��һ��
				count--;
			start++;
			while(!isinT[S[start]])
				start++;
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