#include <iostream>
using namespace std;

  struct ListNode {
      int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if(head==NULL)
			return NULL;

		ListNode* cur=head->next;
		if(cur==NULL)
			return head;

		head->next=NULL;//重组head

		ListNode* temp;
		ListNode* temppre=NULL;
		ListNode* nextcur;
		while(cur != NULL)
		{
			nextcur=cur->next;
			temp=head;
			while(temp!=NULL && cur->val>temp->val)
			{
				temppre=temp;
				temp=temp->next;
			}
			//cur插入到temp之前
			if(temp==head)
			{
				cur->next=temp;
				head=cur;
			}
			else if(temp==NULL)
			{
				temppre->next=cur;
				cur->next=NULL;
			}
			else
			{
				cur->next=temp;
				temppre->next=cur;
			}

			cur=nextcur;
		}

		return head;
    }
};

int main()
{
	Solution t;
	ListNode *n1=new ListNode(4);
	ListNode *n2=new ListNode(3);
	n1->next=n2;
	ListNode *n3=new ListNode(1);
	n2->next=n3;
	ListNode *n4=new ListNode(5);
	n3->next=n4;
	ListNode *n5=new ListNode(8);
	n4->next=n5;

	ListNode* newhead=t.insertionSortList(n1);
	while(newhead!=NULL)
	{
		cout<<newhead->val<<endl;
		newhead=newhead->next;
	}

	return 0;
}