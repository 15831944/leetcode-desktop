#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		switch (num.size())  
        {  
        case 0:   
            return 0;  
        case 1:  
            return num[0];  
        case 2:  
            return num[0] + num[1];  
        default:  
            break;  
        }  
		
		sort(num.begin(),num.end());

		
		return sum;
    }

};

int main()
{
	Solution t;
	vector<int> num;
	num.push_back(1);
	num.push_back(2);
	num.push_back(4);
	num.push_back(8);
	num.push_back(16);
	num.push_back(32);
	num.push_back(64);
	num.push_back(128);
	cout<<t.threeSumClosest(num,82);
}