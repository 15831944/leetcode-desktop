#include <iostream>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    void reorderList(ListNode *head) {
		if(head==NULL || head->next==NULL)
			return;
		ListNode *fast=head;
		ListNode *slow=head;
		while(fast!=NULL && fast->next!=NULL)
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		//把slow->next这个链表反转，然后和head做合并
		ListNode *head2=slow->next;
		slow->next=NULL;
		head2=reverselist(head2);

		ListNode *temp1;
		ListNode *temp2;
		ListNode *cur1=head;
		ListNode *cur2=head2;//2短一些
		while(cur2!=NULL)
		{
			temp1=cur1->next;
			temp2=cur2->next;
			cur1->next=cur2;
			cur2->next=temp1;
			cur1=temp1;
			cur2=temp2;
		}
    }

	ListNode *reverselist(ListNode *head)
	{
		if(head==NULL || head->next==NULL)
			return head;
		ListNode *temp;
		ListNode *pre=head;
		ListNode *cur=head->next;
		pre->next=NULL;
		while(cur!=NULL)
		{
			temp=cur->next;
			cur->next=pre;
			pre=cur;
			cur=temp;
		}
		return pre;
	}
};

int main()
{
	Solution t;
	ListNode *n1=new ListNode(1);
	ListNode *n2=new ListNode(2);
	ListNode *n3=new ListNode(3);
	ListNode *n4=new ListNode(4);
	ListNode *n5=new ListNode(5);
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	t.reorderList(n1);
}