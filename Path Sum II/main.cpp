#include <iostream>
#include <vector>
#include <stack>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	vector<vector<int> > re;
	void dfs(TreeNode*root,int sum,vector<int>curvec)//从root出发走到叶结点的和能达到sum
	{
		if(root->val == sum && root->left ==NULL && root->right ==NULL)
		{
			curvec.push_back(root->val);
			re.push_back(curvec);
			return;
		}

		curvec.push_back(root->val);
		if(root->left != NULL)
		{
			dfs(root->left,sum-root->val,curvec);
		}
		if(root->right !=NULL)
		{
			dfs(root->right,sum-root->val,curvec);
		}

		return;
	}

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
       if(root == NULL)
			return re;
		vector<int>cur;
		dfs(root,sum,cur);
		return re;
    }
};

int main()
{
	TreeNode *root=new TreeNode(5);
	TreeNode *r1=new TreeNode(4);
	TreeNode *r2=new TreeNode(8);
	root->left=r1;
	root->right=r2;

	TreeNode *r3=new TreeNode(11);
	r1->left=r3;

	TreeNode *r4=new TreeNode(13);
	r2->left=r4;

	TreeNode *r5=new TreeNode(4);
	r2->right=r5;
	TreeNode *r6=new TreeNode(7);
	TreeNode *r7=new TreeNode(2);
	r3->left=r6;
	r3->right=r7;

	TreeNode *r8=new TreeNode(5);
	TreeNode *r9=new TreeNode(1);
	r5->left=r8;
	r5->right=r9;

	Solution s;
	vector<vector<int> > re=s.pathSum(root,22);
	for(int i=0;i<re.size();i++)
	{
		vector<int> temp=re[i];
		for(int j=0;j<temp.size();j++)
			cout<<temp[j];
		cout<<endl;
	}

}