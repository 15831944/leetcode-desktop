#include <iostream>
#include <vector>
using namespace std;

 struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };
 
class Solution {
public:
	vector<UndirectedGraphNode *> hascloned;
	UndirectedGraphNode *findbylabel(UndirectedGraphNode *node)
	{
		for(int i=0;i<hascloned.size();i++)
		{
			if(hascloned[i]->label == node->label)
				return hascloned[i];
		}
		return NULL;
	}

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == NULL)
			return NULL;

		UndirectedGraphNode *temp;

		UndirectedGraphNode *cnode;

		cnode=new UndirectedGraphNode(node->label);
		hascloned.push_back(cnode);

		for(int i=0;i<node->neighbors.size();i++)
		{
			if(node->neighbors[i]->label == node->label)//×Ô»·
				cnode->neighbors.push_back(cnode);
			else
			{
				temp=findbylabel(node->neighbors[i]);
				if(temp != NULL)
					cnode->neighbors.push_back(temp);
				else
					cnode->neighbors.push_back(cloneGraph(node->neighbors[i]));
			}
		}

		return cnode;
    }
};

int main()
{
	return 0;
}