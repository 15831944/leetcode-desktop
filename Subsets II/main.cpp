#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        //����S�д�С����ÿ��Ԫ�أ������Ƿ����ÿ��������
		sort(S.begin(),S.end());
		int elem_num=S.size();

		vector<int>onesolution;
		vector<vector<int> > subset_set;
		if(S.size()==0)
			return subset_set;
		subset_set.push_back(onesolution);
		for(int i=0;i<elem_num;i++)//����ÿһ��S[i]
		{
			int count=1;
			while(i+1<elem_num && S[i]==S[i+1])
			{
				count++;
				i++;
			}
			//S[i]�����������count�Σ���ô����״̬������5������3�Σ��������0��5�����1��5�����2��5�����3��5�⼸��״̬
			int oldsize=subset_set.size();
			for(int k=0;k<oldsize;k++)//��ǰ��Ľ���ó���������ǰ����ӽ�ȥ���ճ��µĽ�
			{
				//ÿ���������count��S[i]
				vector<int>onesolution=subset_set[k];
				for(int m=1;m<=count;m++)
				{
					onesolution.push_back(S[i]);
					subset_set.push_back(onesolution);
				}
			}
			
		}

		return subset_set;
    }
};

int main()
{
	Solution t;
	vector<int > v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	vector<vector<int> > re=t.subsetsWithDup(v);
	for(int i=0;i<re.size();i++)
	{
		for(int j=0;j<re[i].size();j++)
			cout<<re[i][j]<<" ";
		cout<<endl;
	}
}