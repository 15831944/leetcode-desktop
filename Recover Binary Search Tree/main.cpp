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
	void recoverTree(TreeNode *root) {
		if(root == NULL)
			return;

		TreeNode *pre=NULL;
		TreeNode *point=root;
		TreeNode *wrong1=NULL;
		TreeNode *wrong2=NULL;
		vector<TreeNode *> st;
		while(!st.empty() || point)
		{
			if(point)
			{
				st.push_back(point);
				point=point->left;
			}
			else
			{
				point=st.back();
				st.pop_back();
				//visit
				if(pre != NULL)//为了解决第一次访问时，没有pre
				{
					if(pre->val > point->val)
					{
						if(wrong1 == NULL)//这样如果是相邻的两个错了，都记下来了
						{
							wrong1=pre;
							wrong2=point;
						}
						else//如果不相邻，那么wrong2会被新的更新
							wrong2=point;
					}
				}
				pre=point;
				point=point->right;
			}
		}
		swap(wrong1->val,wrong2->val);
    }
};

int main()
{
	TreeNode *n1=new TreeNode(1);
	TreeNode *n2=new TreeNode(2);
	TreeNode *n3=new TreeNode(3);
	TreeNode *n4=new TreeNode(4);
	TreeNode *n5=new TreeNode(6);
	TreeNode *n6=new TreeNode(5);
	TreeNode *n7=new TreeNode(7);
	n4->left=n2;
	n4->right=n6;
	n2->left=n1;
	n2->right=n3;
	n6->left=n5;
	n6->right=n7;

	Solution t;
	t.recoverTree(n4);
}
