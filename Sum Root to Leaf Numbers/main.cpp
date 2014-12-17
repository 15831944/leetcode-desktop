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
	int sum;
    int sumNumbers(TreeNode *root) {
        sum=0;
		if(root==NULL)
			return 0;
		dfs(root,0);
		return sum;
    }

	void dfs(TreeNode *root,int current)
	{
		if(root->left==NULL&&root->right==NULL)
		{
			sum +=current+root->val;
			return;
		}
		else
		{
			if(root->left!=NULL)
				dfs(root->left,(current+root->val)*10);
			if(root->right!=NULL)
				dfs(root->right,(current+root->val)*10);
		}
	}
};

int main()
{
	TreeNode *r=new TreeNode(1);
	TreeNode *r2=new TreeNode(2);
	TreeNode *r3=new TreeNode(3);
	r->left=r2;
	r->right=r3;
	Solution t;
	cout<<t.sumNumbers(r);
	return 0;
}