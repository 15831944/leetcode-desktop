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
	int result;
	int dfs(TreeNode *root)
	{
		if(root==NULL)
			return 0;

		int temp=root->val;
		int l=dfs(root->left);
		int r=dfs(root->right);

		if(l>0)
			temp+=l;
		if(r>0)
			temp+=r;

		if(temp>result)//这里因为不是返回值，可以同时加上左右来更新最大结果，表示过当前结点，以当前结点为根
			result=temp;

		return max(root->val,max(root->val+l,root->val+r));//注意，这里只能是要么朝左，要么朝右选个最大的返回
	}

	int maxPathSum(TreeNode *root) {
		result=INT_MIN;
		dfs(root);
		return result;
    }
};

int main()
{
	Solution t;
	TreeNode *root=new TreeNode(5);
	TreeNode *n1=new TreeNode(-2);
	TreeNode *n2=new TreeNode(1);
	TreeNode *n3=new TreeNode(-1);
	TreeNode *n4=new TreeNode(4);
	root->right=n1;
	n1->left=n2;
	n1->right=n3;
	n3->right=n4;

	cout<<t.maxPathSum(root);

	return 0;
}