#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m==n)
			return head;

		ListNode *prehead=new ListNode(-1);
		prehead->next=head;

		ListNode *nodempre=prehead;
		ListNode *nodenpre=prehead;
		while(m>1)
		{
			nodempre=nodempre->next;
			m--;
		}
		while(n>1)
		{
			nodenpre=nodenpre->next;
			n--;
		}

		//要删除的是相邻的结点
		if(nodempre->next==nodenpre)
		{
			ListNode *tempm=nodempre->next;
			nodempre->next=nodenpre->next;
			tempm->next=nodempre->next->next;
			nodempre->next->next=tempm;
		}

		else
		{
			ListNode *tempmnext=nodempre->next->next;
			ListNode *tempm=nodempre->next;
			nodempre->next=nodenpre->next;
			tempm->next=nodenpre->next->next;
			nodenpre->next->next=tempmnext;
			nodenpre->next=tempm;
		}
		return prehead->next;
    }
};

int main()
{
	ListNode *n1=new ListNode(1);
	ListNode *n2=new ListNode(2);
	ListNode *n3=new ListNode(3);
	ListNode *n4=new ListNode(4);
	ListNode *n5=new ListNode(5);

	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	//n4->next=n5;

	Solution t;
	ListNode *temp=t.reverseBetween(n1,1,4);
	return 0;
}