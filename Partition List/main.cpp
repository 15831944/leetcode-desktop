#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
		if(head==NULL || head->next==NULL)
			return head;
		ListNode *h0=new ListNode(INT_MIN);
		h0->next=head;//�¿�һ��ͷ�����ڲ���
		ListNode *patitionpoint=h0;
		ListNode *cur=h0->next;
		ListNode *curpre=h0;
		while(cur!=NULL)
		{
			if(cur->val>=x)
			{
				curpre=cur;
				cur=cur->next;
			}
			else
			{
				if(patitionpoint->next==cur)//cur�պ���patitionpoint֮��ֱ���ƶ�patitionpoint����
				{
					patitionpoint=cur;
					curpre=cur;
					cur=cur->next;
				}
				else//��cur���뵽patitionpoint֮��
				{
					curpre->next=cur->next;
					cur->next=patitionpoint->next;
					patitionpoint->next=cur;
					patitionpoint=cur;
					cur=curpre->next;
				}
			}
		}
		return h0->next;
    }
};

int main()
{
	Solution t;
	
	ListNode *n1=new ListNode(1);
	ListNode *n2=new ListNode(4);
	ListNode *n3=new ListNode(3);
	ListNode *n4=new ListNode(2);
	ListNode *n5=new ListNode(5);
	ListNode *n6=new ListNode(2);
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	n4->next=n5;
	n5->next=n6;
	ListNode *res=t.partition(n1,3);
	return 0;
}