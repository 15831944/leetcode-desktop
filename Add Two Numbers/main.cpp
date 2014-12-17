#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
			return l2;
		if(l2==NULL)
			return l1;

		int jinwei=(l1->val+l2->val)/10;
		l1->val=(l1->val+l2->val)%10;
		l2->val=l1->val;
		

		ListNode *pre1=l1;
		ListNode *pre2=l2;
		ListNode *temp1=l1->next;
		ListNode *temp2=l2->next;

		int old;
		while(temp1 !=NULL && temp2!=NULL)
		{
			old=temp1->val;
			temp1->val = (temp1->val+temp2->val+jinwei)%10;
			jinwei=(old+temp2->val+jinwei)/10;
			temp2->val=temp1->val;//两个链表都作改变
			

			temp1=temp1->next;
			temp2=temp2->next;

			pre1=pre1->next;
			pre2=pre2->next;
		}
		if(temp1==NULL && temp2!=NULL)//说明l1短
		{
			while(temp2!=NULL)
			{
				old=temp2->val;
				temp2->val=(temp2->val+jinwei)%10;
				jinwei=(old+jinwei)/10;
				temp2=temp2->next;
				pre2=pre2->next;
			}
			if(jinwei==0)
				return l2;
			else
			{
				pre2->next=new ListNode(1);
				return l2;
			}
		}
		else if(temp2==NULL && temp1!=NULL)
		{
			while(temp1!=NULL)
			{
				old=temp1->val;
				temp1->val=(temp1->val+jinwei)%10;
				jinwei=(old+jinwei)/10;
				temp1=temp1->next;
				pre1=pre1->next;
			}
			if(jinwei==0)
				return l1;
			else
			{
				pre1->next=new ListNode(1);
				return l1;
			}
		}
		else//一样长
		{
			if(jinwei==0)
				return l1;
			else
			{
				pre1->next=new ListNode(1);
				return l1;
			}
		}
		
    }
};

int main()
{
	ListNode *l1=new ListNode(1);
	ListNode *l2=new ListNode(9);
	l2->next=new ListNode(9);
	Solution t;
	ListNode *l3=t.addTwoNumbers(l1,l2);
	while(l3!=NULL)
	{
		cout<<l3->val<<" ";
		l3=l3->next;
	}
	return 0;
}