#include <iostream>
#include <unordered_map>
using namespace std;

class Node{
public:
	int key;
	Node* pre;
	Node*next;
	Node(int v)
	{
		key=v;
		pre=NULL;
		next=NULL;
	}
};

class LRUCache{
private:
	int cap;
	unordered_map<int ,int> page;
	Node* head;
	Node* tail;
public:
    LRUCache(int capacity) {
        this->cap=capacity;
		head=NULL;
		tail=NULL;
    }
    
    int get(int key) {
		unordered_map<int,int>::const_iterator it=page.find(key);
		if( it== page.end())
			return -1;
		else//访问它了，调到头
		{
			Node*temp=head;
			while(temp->key!=key)
				temp=temp->next;

			if(temp !=head)
			{
				if(temp == tail)
				{
					tail=temp->pre;
					temp->pre->next=NULL;
					temp->pre=NULL;
					temp->next=head;
					head->pre=temp;
					head=temp;
				}
				else
				{
					temp->pre->next=temp->next;
					temp->next->pre=temp->pre;

					temp->next=head;
					temp->pre=NULL;
					head->pre=temp;
					head=temp;
				}
			}

			return it->second;
		}
    }
    
    void set(int key, int value) {
        unordered_map<int,int>::const_iterator it=page.find(key);
		if(it == page.end())//不存在，考虑大小
		{
			if(page.size() == cap)//如果满了，则把最后的删除掉，当前加到链表头
			{
				Node *temp=new Node(key);
				temp->next=head;
				head->pre=temp;
				head=temp;
				page[key]=value;

				temp=tail;
				page.erase(temp->key);
				tail=temp->pre;
				tail->next=NULL;
				delete temp;
			}
			else//没满，直接加到头
			{
				if(head==NULL)
				{
					Node *temp=new Node(key);
					head=temp;
					tail=temp;

					page[key]=value;
				}

				else
				{
					Node *temp=new Node(key);
					temp->next=head;
					temp->pre=NULL;
					head->pre=temp;
					head=temp;

					page[key]=value;
				}
			}
		}
		else//找到了，调整key到最前面
		{
			Node*temp=head;
			while(temp->key!=key)
				temp=temp->next;

			if(temp !=head)
			{
				if(temp == tail)
				{
					tail=temp->pre;
					temp->pre->next=NULL;
					temp->pre=NULL;
					temp->next=head;
					head->pre=temp;
					head=temp;
				}
				else
				{
					temp->pre->next=temp->next;
					temp->next->pre=temp->pre;

					temp->next=head;
					temp->pre=NULL;
					head->pre=temp;
					head=temp;
				}
			}
			page[key]=value;
		}
    }
	
};

int main()
{
	LRUCache t(2);
	t.set(2,1);
	t.set(1,1);
	cout<<t.get(2)<<endl;
	t.set(4,1);
	cout<<t.get(1)<<endl;
	cout<<t.get(2)<<endl;
	
}