#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> res;        

		int start=0;
		int end=0;
		while(start<words.size())
		{
			end=start;
			string currow="";
			int charcount=0;
			int charandspacecount=0;
			while(end<words.size() && charandspacecount +words[end].length() <= L)
			{
				charcount += words[end].length();
				charandspacecount += words[end].length();
				charandspacecount ++;
				end++;
			}
			//��Ϊû�е�end������������
			end--;
			//��ʼ����start��end�����Կո�����L-charcount��ƽ�����䵽wordleng.size()�������м�
			int spacecount=L-charcount;//�ո���
			int wordscount=end-start+1;//������
			if(wordscount==1)//ֻ��һ�����ʣ�ֱ�ӵ��ʼӿո񵽵�
			{
				currow += words[start];
				string spa(spacecount,' ');
				currow += spa;
			}
			else
			{
				if(end==words.size()-1)//��������һ�У������
				{
					for(int i=start;i<end;i++)
						currow=currow+words[i]+' ';
					currow+=words[end];
					string spa(spacecount-(wordscount-1),' ');
					currow+=spa;
				}
				else
				{
					int basespacecount=spacecount/(wordscount-1);
					string basespace(basespacecount,' ');
					int addspace=spacecount%(wordscount-1);
					for(int i=start;i<end;i++)
					{
						currow += words[i];//��ӵ���
						currow += basespace;//ƽ����ӿո�
						if(addspace>0)
						{
							currow += ' ';
							addspace--;
						}
					}
					currow += words[end];//��󵥴�û�пո�
				}
			}
			res.push_back(currow);
			//��һ�п�ʼ�ĵ�����start
			start=end+1;
		}
		return res;
    }
};

int main()
{
	Solution t;
	vector<string> words;
	words.push_back("This");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification");
	vector<string> res=t.fullJustify(words,16);

	return 0;
}