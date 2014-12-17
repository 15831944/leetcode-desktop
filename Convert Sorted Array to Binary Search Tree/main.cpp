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
    TreeNode *sortedArrayToBST(vector<int> &num) {
		int size=num.size();
		if(size==0)
			return NULL;
		return buildroot(num,0,size-1);
    }

	TreeNode *buildroot(vector<int> &num,int start,int end)
	{
		if(start==end)
			return new TreeNode(num[start]);

		int mid=(start+end)/2;
		TreeNode *root=new TreeNode(num[mid]);
		if(start<=mid-1)
			root->left=buildroot(num,start,mid-1);
		else
			root->left=NULL;
		if(mid+1<=end)
			root->right=buildroot(num,mid+1,end);
		else
			root->right=NULL;

		return root;
	}
};

int main()
{
	Solution t;
	vector<int>num;
	num.push_back(1);
	num.push_back(3);


	TreeNode *root=t.sortedArrayToBST(num);
	cout<<root->val<<endl;
	//cout<<root->left->val<<endl;
	cout<<root->right->val<<endl;

}