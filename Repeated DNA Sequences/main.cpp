#include <iostream>
#include <vector>
#include <functional>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<size_t, int> hashstoint;
		vector<string> result;
		hash<string> hashfn;
		string current;
		for (int i = 0; i+9 < s.length(); ++i)
		{
			current = s.substr(i, 10);
			if (hashstoint.find(hashfn(current)) == hashstoint.end())
				hashstoint[hashfn(current)] = 1;
			else if (hashstoint[hashfn(current)] == 1)
			{
				hashstoint[hashfn(current)] = -1;//标记为-1表示已经加到结果中了
				result.push_back(current);
			}
		}
		return result;
	}
};

int main()
{
	Solution t;
	vector<string> res = t.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
}