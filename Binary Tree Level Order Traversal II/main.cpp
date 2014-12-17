#include <iostream>
#include <vector>
#include <queue>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> >res;
		if(root==NULL)
			return res;

		vector<vector<int>*> fanxu;

		TreeNode* temp;
		queue<TreeNode*> mq;
		mq.push(root);

		int currentlevel=1;
		int nextlevel=0;

		while(!mq.empty())
		{
			vector<int>* clevel=new vector<int>;
			while(currentlevel--)
			{
				temp=mq.front();
				mq.pop();

				clevel->push_back(temp->val);

				if(temp->left!=NULL)
				{
					mq.push(temp->left);
					nextlevel++;
				}
				if(temp->right!=NULL)
				{
					mq.push(temp->right);
					nextlevel++;
				}
			}
			currentlevel=nextlevel;
			nextlevel=0;
			fanxu.push_back(clevel);
		}

		while(!fanxu.empty())
		{
			res.push_back(*fanxu.back());
			fanxu.pop_back();
		}

		return res;
    }
};

int main()
{
	Solution t;
	TreeNode *root=new TreeNode(3);
	TreeNode *r2=new TreeNode(9);
	TreeNode *r3=new TreeNode(20);
	root->left=r2;
	root->right=r3;
	vector<vector<int> >res=t.levelOrderBottom(root);

	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}