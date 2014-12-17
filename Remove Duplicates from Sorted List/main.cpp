#include <iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head==NULL)
			return NULL;
		ListNode *temp;
		ListNode *temphead;
		ListNode *cur=head;
		ListNode *nex=head->next;
		while(nex !=NULL && cur->val==nex->val)
		{
			temp=cur;
			cur=cur->next;
			nex=nex->next;
			delete temp;
		}
		head=cur;

		while(nex !=NULL)
		{
			if(cur->val != nex->val)
			{
				cur=cur->next;
				nex=nex->next;
			}
			else
			{
				temphead=cur;

				cur=cur->next;
				nex=nex->next;
				while(nex !=NULL && cur->val==nex->val)
				{
					temp=cur;
					cur=cur->next;
					nex=nex->next;
					delete temp;
				}
				delete cur;

				temphead->next=nex;

				if(nex==NULL)
					break;
				cur=nex;
				nex=nex->next;
			}
		}
		return head;

    }
};

int main()
{
	Solution t;
	ListNode *n1=new ListNode(1);
	ListNode *n2=new ListNode(2);
	n1->next=n2;
	ListNode *n3=new ListNode(2);
	n2->next=n3;
	ListNode *n4=new ListNode(3);
	n3->next=n4;
	ListNode *n5=new ListNode(3);
	n4->next=n5;
	ListNode *n6=new ListNode(6);
	n5->next=n6;
	ListNode * head=t.deleteDuplicates(n1);
	while(head!=NULL)
	{
		cout<<head->val<<endl;
		head=head->next;
	}
	
}