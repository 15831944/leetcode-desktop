#include <iostream>
using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        if(str==NULL)
			return 0;

		long long result=0;
		bool negative=false;
		int fuhao=0;
		//ÇåÀí¿Õ¸ñ
		int i=0;
		while(str[i] != '\0' && str[i]==' ')
			i++;

		for(;str[i] != '\0';i++)
		{
			if(str[i]== '-')
			{
				negative=true;
				fuhao++;
				if(fuhao>1)
					return 0;
				continue;
			}
			else if(str[i]== '+')
			{
				negative=false;
				fuhao++;
				if(fuhao>1)
					return 0;
				continue;
			}
			else if(str[i] >= '0' && str[i] <='9')
			{
				result = result*10+str[i]-'0';
				if(!negative && result>INT_MAX)
					return INT_MAX;
				else if(negative && 0-result<INT_MIN)
					return INT_MIN;
			}
			else
				break;
		}

		if(negative)
			return 0-result;
		else
			return result;
    }
};

int main()
{
	Solution t;
	cout<<t.atoi("9223372036854775809");
	return 0;
}