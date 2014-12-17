#include <iostream>
#include<vector>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
		if(root==NULL)
			return result;

		vector<TreeNode*>st;
		TreeNode* temp=root;

		while(!st.empty() || temp)
		{
			if(temp)
			{
				//visit
				result.push_back(temp->val);
				
				if(temp->right!=NULL)
					st.push_back(temp->right);
				temp=temp->left;
			}
			else
			{
				temp=st.back();
				st.pop_back();
			}
		}
		return result;
    }
};

int main()
{
	TreeNode *root=new TreeNode(1);
	TreeNode *r1=new TreeNode(2);
	TreeNode *r2=new TreeNode(3);
	Solution t;
	root->right=r1;
	r1->left=r2;
	vector<int>res=t.inorderTraversal(root);
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;

}