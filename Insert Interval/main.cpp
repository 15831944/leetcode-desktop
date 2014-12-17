#include <iostream>
#include <vector>
using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		if(intervals.size()==0)
		{
			intervals.push_back(newInterval);
			return intervals;
		}
		int i=0;
		while(i<intervals.size())
		{

			while(i<intervals.size() && newInterval.start>=intervals[i].end)
				i++;
			//¥À ±newinterval.start<intervals[i].end
			if(i==intervals.size())
			{
				intervals.push_back(newInterval);
				return intervals;
			}

		}

    }
};