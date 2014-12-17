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

		//p�����ң��ҵ����һ����ͬ��
		while(p->next!=NULL && p->val == p->next->val){
			p=p->next;
		}

		//��ʱ������head��û���֣���Ҫ�ݹ�������head
		if(p!=head){
			while(head!=p->next)//����ֱ����ָ��ֵ���Ƚϴ�С��������
			{
				ListNode * tmp = head;
				head=head->next;
				free(tmp);
			}

			return deleteDuplicates(p->next);
		}

		//���p==head����˵��head��head��һ����ͬ��ֱ��return head������return ֮ǰ���ҵ�head->next
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