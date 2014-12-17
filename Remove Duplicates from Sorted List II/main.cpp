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
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(head==NULL || head->next==NULL)
			return head;
		ListNode * p = head;

		//p往后找，找到最后一个相同的
		while(p->next!=NULL && p->val == p->next->val){
			p=p->next;
		}

		//此时真正的head还没出现，还要递归往后找head
		if(p!=head){
			while(head!=p->next)//这里直接用指针值来比较大小，很巧妙
			{
				ListNode * tmp = head;
				head=head->next;
				free(tmp);
			}

			return deleteDuplicates(p->next);
		}

		//如果p==head，则说明head与head后一个不同，直接return head，但在return 之前先找到head->next
		head->next=deleteDuplicates(head->next);
		return head;
	}
};

int main()
{
	Solution t;
	ListNode *head=new ListNode(1);
	ListNode *n=new ListNode(2);
	head->next=n;
	cout<<t.deleteDuplicates(head)<<endl;
}