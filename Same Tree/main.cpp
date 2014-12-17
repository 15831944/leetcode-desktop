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
    bool isSameTree(TreeNode *p, TreeNode *q) {
		if(p == NULL && q==NULL)
			return true;
		else if(p !=NULL && q == NULL || p==NULL && q != NULL)
			return false;

		else if(p->val==q->val)
		{
			if(p->left == NULL && q->left==NULL)
			{
				if(p->right == NULL && q->right==NULL)
					return true;
				else if(p->right != NULL && q->right!=NULL)
					return isSameTree(p->right,q->right);
				else
					return false;
			}

			else if(p->left != NULL && q->left!=NULL)
			{
				if(p->right == NULL && q->right==NULL)
					return isSameTree(p->left,q->left);
				else if(p->right != NULL && q->right!=NULL)
					return isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
				else
					return false;
			}

			else
				return false;
		}
		else
			return false;
    }
};

int main()
{
}