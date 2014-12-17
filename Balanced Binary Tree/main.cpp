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
    bool isBalanced(TreeNode *root) {
        if(root==NULL)
			return true;
		else if(root->left==NULL && root->right==NULL)
			return true;
		else if(root->left==NULL && root->right!=NULL)
		{
			if(depth(root->right)>1)
				return false;
			else
				return true;
		}
		else if(root->left!=NULL && root->right==NULL)
		{
			if(depth(root->left)>1)
				return false;
			else
				return true;
		}
		else
		{
			if( abs(depth(root->left)-depth(root->right)) >1 )
				return false;
			else
				return isBalanced(root->left) && isBalanced(root->right);
		}

    }

	int depth(TreeNode *root)
	{
		if(root==NULL)
			return 0;
		else if(root->left==NULL && root->right==NULL)
			return 1;
		else if(root->left==NULL && root->right!=NULL)
			return 1+depth(root->right);
		else if(root->left!=NULL && root->right==NULL)
			return 1+depth(root->left);
		else
			return 1+max(depth(root->left),depth(root->right));
	}
};

int main()
{}