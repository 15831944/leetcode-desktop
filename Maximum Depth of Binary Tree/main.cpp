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
    int dfs(TreeNode *current,int depth)
	{
		if(current->left == NULL && current->right ==NULL)
			return depth;

		int left=0;
		int right=0;
		if(current->left)
			left+=dfs(current->left,depth+1);

		if(current->right)
			right+=dfs(current->right,depth+1);

		return max(left,right);
	}
    
    int maxDepth(TreeNode *root) {
		if(root == NULL)
			return 0;
        return dfs(root,1);
    }
};

int main()
{
	TreeNode *root=new TreeNode(1);
	TreeNode *r1=new TreeNode(2);
	TreeNode *r2=new TreeNode(3);
	root->left=r1;
	r1->left=r2;
	Solution t;
	cout<<t.maxDepth(root);
	return 0;
}