#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		int a,b;//Á½²Ù×÷Êý
		stack <int> s;
        for(vector<string>::const_iterator it=tokens.begin();it<tokens.end();++it)
		{
			if(( (*it)[0] == '+' || (*it)[0] == '-' ||(*it)[0] == '*' ||(*it)[0] == '/' ) && (*it).size()==1)
			{
				b=s.top();
				s.pop();
				a=s.top();
				s.pop();

				switch((*it)[0])
				{
					case '+':
					 {
						 s.push(a+b);
						 break;
					  }
					  case '-':
					  {
						 s.push(a-b);
						break;
					  }
					  case '*':
					  {
						  s.push(a*b);
						 break;
					  }
					  case '/':
					  {
						  s.push(a/b);
						 break;
					  }
				}

			}
			else
			{
				s.push(atoi((*it).c_str()));
			}
		}

		return s.top();
    }
};

int main()
{
	Solution test;
	vector<string> p;
	p.push_back("-1");
	p.push_back("1");
	p.push_back("*");
	p.push_back("-1");
	p.push_back("+");
	cout<<test.evalRPN(p)<<endl;

	return 0;
}