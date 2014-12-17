#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *fast=head;
		ListNode *slow=head;

		//fast先走n，然后slow和fast一起走
		while(n--)
			fast=fast->next;
		if( NULL == fast)//要删除第一个
		{
		    ListNode *temp=head->next;
		    delete head;
		    return temp;
		}
		while(fast->next)
		{
			fast=fast->next;
			slow=slow->next;
		}
		ListNode *temp=slow->next;
		slow->next=slow->next->next;
		delete temp;

		return head;
    }
};

int main()
{
	Solution t;

}