#include <iostream>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL)
			return NULL;
		else if(head->next==NULL)
			return head;
		
		ListNode* newhead=head->next;
		ListNode* cur=head;
		ListNode* nex=head->next;

    }
};