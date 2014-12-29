#include <iostream>
#include <stack>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void preorderTraversal(TreeNode *root) {
		stack<TreeNode*>st;//用这个栈操作，需要用到的有push()，pop()，top();
		//To do...
}

int main()
{
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	n1->left = n2;
	n1->right = n3;
	TreeNode *n4 = new TreeNode(4);
	n2->right = n4;
	TreeNode *n5 = new TreeNode(5);
	n3->right = n5;
	TreeNode *n6 = new TreeNode(6);
	TreeNode *n7 = new TreeNode(7);
	n4->left = n6;
	n4->right = n7;
	TreeNode *n8 = new TreeNode(8);
	n5->right = n8;
	//preorderTraversal(n1);
	cout << (-1) / 2;
	return 0;
}
