#include <iostream>
#include <queue>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> >result;
		queue<TreeNode *> q;
		if(root==NULL)
			return result;

		q.push(root);
		int currentlevelcount=1;
		int level=0;
		while(!q.empty())
		{
			int nextlevelcount=0;
			vector<int> currentlevel;
			while(currentlevelcount--)
			{
				TreeNode *temp=q.front();
				q.pop();
				currentlevel.push_back(temp->val);
				if(temp->left)
				{
					q.push(temp->left);
					nextlevelcount++;
				}
				if(temp->right)
				{
					q.push(temp->right);
					nextlevelcount++;
				}
			}

			if(level % 2==0)
				result.push_back(currentlevel);
			else//¶Ôcurrentlevel·´Ðò
			{
				int n=currentlevel.size();
				int temp;
				for(int i=0;i<n/2;i++)
				{
					temp=currentlevel[i];
					currentlevel[i]=currentlevel[n-1-i];
					currentlevel[n-1-i]=temp;
				}
				result.push_back(currentlevel);
			}
			currentlevelcount=nextlevelcount;
			level++;
		}

		return result;
    }
};

int main()
{
	Solution s;
	TreeNode *root=new TreeNode(3);
	TreeNode *r1=new TreeNode(9);
	TreeNode *r2=new TreeNode(20);
	TreeNode *r3=new TreeNode(15);
	TreeNode *r4=new TreeNode(7);
	root->left=r1;
	root->right=r2;
	r2->left=r3;
	r2->right=r4;
	vector<vector<int> >result=s.zigzagLevelOrder(root);

	for(int i=0;i<result.size();i++)
	{
		vector<int> l=result[i];
		for(int j=0;j<l.size();j++)
		{
			cout<<l[j]<<" ";
		}
		cout<<endl;
	}
}