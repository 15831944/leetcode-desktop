#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {  
        // Note: The Solution object is instantiated only once.  
        long long a = abs((double)dividend);  
        long long b = abs((double)divisor);  
        long long res = 0;  
        while(a >= b)  
        {  
            long long c = b;  
            for(int i = 0; a >= c; i++, c <<=1)  
            {  
                a -= c;  
                res += 1<<i;  
            }  
        }  
        return ((dividend ^ divisor) >> 31) ? (-res) : (res);  
    }  
};

int main()
{
	Solution t;
	cout<<t.divide(-1,-1)<<endl;
}