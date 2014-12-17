#include <iostream>
using namespace std;

//ע�⣬ָ�벻����if(!point)��ֻ��if(point)��ʾpoint���յ����
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *head=NULL;
		ListNode *t=NULL;
		if(NULL==l1)
			return l2;
		if(NULL==l2)
			return l1;

		if(l1->val>l2->val)
		{
			t=l1;
			l1=l2;
			l2=t;
		}

		//��l2��l1���
		head=l1;
		while(l2)//����l2��ÿһ��Ԫ��
		{
			while(l1->next !=NULL && l1->next->val < l2->val)
				l1=l1->next;
			if(l1->next == NULL)
			{
				l1->next=l2;
				break;
			}
				
			ListNode *temp=l1->next;
			ListNode *temp2=l2->next;
			l1->next=l2;
			l2->next=temp;

			l2=temp2;
		}
		return head;
    }
};

int main()
{
	Solution s;
	if(!s.mergeTwoLists(NULL,NULL))
		cout<<"��"<<endl;
	return 0;
}