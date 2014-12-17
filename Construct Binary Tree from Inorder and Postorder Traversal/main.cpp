#include <iostream>
#include <vector>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if(inorder.size()==0 || postorder.size()==0)
			return NULL;
		return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }

	TreeNode *build(vector<int> &inorder,int instart,int inend,vector<int> &postorder,int postart,int poend)
	{
		if(instart==inend || postart==poend)
			return new TreeNode(inorder[instart]);
		if(instart>inend || postart>poend)
			return NULL;

		TreeNode *root=new TreeNode(postorder[poend]);
		int i;
		for(i=instart;i<=inend;i++)
			if(inorder[i]==postorder[poend])
				break;

		root->left=build(inorder,instart,i-1,postorder,postart,postart+i-instart-1);
		root->right=build(inorder,i+1,inend,postorder,postart+i-instart,poend-1);
		return root;
	}
};

int main()
{
	int a[]={2,1};
	vector<int> in(a,a+2);
	int b[]={1,2};
	vector<int> po(b,b+2);
	Solution t;
	TreeNode *res=t.buildTree(in,po);
}