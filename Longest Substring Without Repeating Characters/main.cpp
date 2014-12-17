#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if(s.size()==0)
			return 0;
		int size=s.size();

		unordered_map<char,int> current;
		int maxlength=INT_MIN;
		int start=0;
		int end=0;
		while(end<size)
		{
			while(end<size && current.find(s[end]) == current.end())
			{
				current[s[end]]=end;
				end++;
			}
			//s[end]��current�еڶ��γ��֣���ô��ǰ�����start��end-1
			if(end-1-start+1>maxlength)
				maxlength=end-1-start+1;
			if(end==size)
				break;

			//�Ѻ�s[end]��ͬ��֮ǰ�Ķ�erase��
			while(s[start] != s[end])
			{
				current.erase(s[start]);
				start++;
			}
			current.erase(s[start]);
			start++;
		}
		return maxlength;
    }
};

int main()
{
	Solution t;
	cout<<t.lengthOfLongestSubstring("aa");
}