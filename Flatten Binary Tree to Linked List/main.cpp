#include <iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL)
			return;
		if(root->left==NULL && root->right==NULL)
			return;

		if(root->left != NULL)//��������flatten
			flatten(root->left);
		if(root->right != NULL)//��������flatten
			flatten(root->right);
		//����ҵ�root�ұߣ��ҹҵ����������±�
		if(root->left == NULL)
			return;
		TreeNode *temp=root->left;
		while(temp->right != NULL)
			temp=temp->right;
		//temp�������������±�
		temp->right=root->right;
		root->right=root->left;
		root->left=NULL;
    }
};

int main()
{
	TreeNode *n1=new TreeNode(1);
	TreeNode *n2=new TreeNode(2);
	TreeNode *n3=new TreeNode(3);
	TreeNode *n4=new TreeNode(4);
	TreeNode *n5=new TreeNode(5);
	TreeNode *n6=new TreeNode(6);
	n1->left=n2;
	n1->right=n5;
	n2->left=n3;
	n2->right=n4;
	n5->right=n6;

	Solution t;
	t.flatten(n1);

	return 0;
}