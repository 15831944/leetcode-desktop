#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
		if(k==0 || head==NULL || head->next==NULL)
			return head;
		ListNode *first=head;
		ListNode *second=head;
		while(k--)
		{
			first=first->next;
			if(first==NULL)
				first=head;
		}
		while(first->next != NULL)
		{
			first=first->next;
			second=second->next;
		}
		first->next=head;
		ListNode *newhead=second->next;
		second->next=NULL;
		return newhead;
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
	ListNode *temp=t.rotateRight(n1,5);
}