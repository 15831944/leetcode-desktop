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
    int minDepth(TreeNode *root) {
		if(root==NULL)
			return 0;
		int min=INT_MAX;
		dfs(root,1,min);
        return min;
    }

	void dfs(TreeNode *root,int current,int &min)
	{
		if(root->left ==NULL && root->right==NULL)
		{
			if(current<min)
				min=current;
			return;
		}
		else
		{
			if(root->left !=NULL)
				dfs(root->left,current+1,min);
			if(root->right!=NULL)
				dfs(root->right,current+1,min);
		}
	}
};

int main()
{}