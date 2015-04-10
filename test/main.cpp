#include <iostream>
using namespace std;

struct Test{
	int a;
	char b;
	short c;
};

int main(int argc, char* argv[])
{
	cout << sizeof(Test) << endl;
	Test test;
	cout << sizeof(test) << endl;
}