#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<string> res;
		unordered_map<string, vector<int>> anagramtoindex;
		for (int i = 0; i < strs.size();++i)
		{
			string current=strs[i];
			sort(current.begin(), current.end());
			anagramtoindex[current].push_back(i);
		}
		for (unordered_map<string, vector<int>>::iterator it = anagramtoindex.begin(); it != anagramtoindex.end(); ++it)
		{
			if (it->second.size()>1)
			{
				for (int i = 0; i < it->second.size(); ++i)
					res.push_back(strs[it->second[i]]);
			}
		}
		return res;
	}
};

int main()
{
	Solution t;

}