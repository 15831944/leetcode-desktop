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
			//因为没有到end，把它拉回来
			end--;
			//开始调整start到end，所以空格数是L-charcount，平均分配到wordleng.size()个单词中间
			int spacecount=L-charcount;//空格数
			int wordscount=end-start+1;//单词数
			if(wordscount==1)//只有一个单词，直接单词加空格到底
			{
				currow += words[start];
				string spa(spacecount,' ');
				currow += spa;
			}
			else
			{
				if(end==words.size()-1)//如果是最后一行，左对齐
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
						currow += words[i];//添加单词
						currow += basespace;//平均添加空格
						if(addspace>0)
						{
							currow += ' ';
							addspace--;
						}
					}
					currow += words[end];//最后单词没有空格
				}
			}
			res.push_back(currow);
			//新一行开始的单词是start
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