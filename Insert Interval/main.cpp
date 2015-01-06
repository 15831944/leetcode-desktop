#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
 
bool compareInterval(Interval i1, Interval i2)
{
	return i1.start < i2.start;
}

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		intervals.push_back(newInterval);
		sort(intervals.begin(),intervals.end(), compareInterval);
		vector<Interval> res;
		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); ++i)
		{
			if (intervals[i].start <= res.back().end)
				res.back().end = max(res.back().end, intervals[i].end);
			else
				res.push_back(intervals[i]);
		}
		return res;
    }
};

int main()
{
	Solution t;
	Interval i1(1, 2);
	Interval i2(3, 5);
	Interval i3(6, 7);
	Interval i4(8, 10);
	Interval i5(12, 16);
	Interval i6(4, 9);
	vector<Interval> vec;
	vec.push_back(i1);
	vec.push_back(i2);
	vec.push_back(i3);
	vec.push_back(i4);
	vec.push_back(i5);
	vector<Interval> res = t.insert(vec, i6);
}