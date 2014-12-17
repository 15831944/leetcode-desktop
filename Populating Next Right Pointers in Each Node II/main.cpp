#include <iostream>
#include <queue>
using namespace std;

  struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==NULL)
			return;
		queue<TreeLinkNode *>myq;
		myq.push(root);

		int currentlevel=1;
		int nextlevel=0;

		while(!myq.empty())
		{
			while(currentlevel>0)
			{
				TreeLinkNode *temp=myq.front();
				myq.pop();
				if(currentlevel==1)
					temp->next=NULL;
				else
					temp->next=myq.front();

				if(temp->left!=NULL)
				{
					myq.push(temp->left);
					nextlevel++;
				}

				if(temp->right!=NULL)
				{
					myq.push(temp->right);
					nextlevel++;
				}
				currentlevel--;
			}

			currentlevel=nextlevel;
			nextlevel=0;
		}

    }
};

int main()
{
	TreeLinkNode *root=new TreeLinkNode(4);
	root->left=new TreeLinkNode(3);
	root->right=new TreeLinkNode(2);
	root->left->left=new TreeLinkNode(1);
	Solution t;
	t.connect(root);
	cout<<root->left->next->val<<endl;

}