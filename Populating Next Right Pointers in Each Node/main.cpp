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
        queue<TreeLinkNode*> mq;
		mq.push(root);
		int currentlevel=0;
		int count;
		while(!mq.empty())
		{
			count=pow(2.0,currentlevel);
			TreeLinkNode*head=mq.front();
			mq.pop();
			if(head->left != NULL)
					mq.push(head->left);
			if(head->right!=NULL)
					mq.push(head->right);
			count--;
			while(count--)
			{
				TreeLinkNode* cp=mq.front();
				mq.pop();
				if(cp->left != NULL)
					mq.push(cp->left);
				if(cp->right!=NULL)
					mq.push(cp->right);

				head->next=cp;
				head=cp;
			}
			head->next=NULL;

			currentlevel++;
		}
    }
};