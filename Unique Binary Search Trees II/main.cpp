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
    vector<TreeNode *> generateTrees(int n) {
        return maketree(1,n);
    }

	vector<TreeNode *> maketree(int from,int to)
	{
		vector<TreeNode *> curres;
		if(from>to)
		{
			curres.push_back(NULL);
			return curres;
		}
		else if(from==to)
		{
			curres.push_back(new TreeNode(from));
			return curres;
		}

		for(int v=from;v<=to;v++)//第一个都做根
		{
			vector<TreeNode *> leftvect=maketree(from,v-1);
			vector<TreeNode *> rightvect=maketree(v+1,to);
			for(int i=0;i<leftvect.size();i++)
				for(int j=0;j<rightvect.size();j++)
				{
					TreeNode *root=new TreeNode(v);
					root->left=leftvect[i];
					root->right=rightvect[j];
					curres.push_back(root);
				}
		}
		return curres;
	}
};

int main()
{
	Solution t;
	vector<TreeNode *> res=t.generateTrees(3);
}