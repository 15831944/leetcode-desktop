#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		map<int,int> hash;
		vector<int> result;
		for(int i=0;i<numbers.size();i++)
		{
			int numtofind=target-numbers[i];

			//�ڲ���i֮ǰ�ģ�����û��numtofind
			if(hash.find(numtofind) != hash.end())
			{
				//�ҵ���
				result.push_back(hash[numtofind]+1);
				result.push_back(i+1);
				return result;
			}

			//ÿ�ΰѵ�ǰ��֮ǰ�Ļ��۵�hash��
			hash[numbers[i]]=i;
		}
    }
};

int main()
{
	Solution t;
	vector<int> p;
	p.push_back(2);
	p.push_back(7);
	p.push_back(11);
	p.push_back(15);

	cout<<t.twoSum(p,9)[0]<<" "<<t.twoSum(p,9)[1]<<endl;
}