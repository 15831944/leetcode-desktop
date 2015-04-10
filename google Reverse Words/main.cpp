#include <fstream>
using namespace std;

int main()
{
	fstream file("B-large-practice.in");
	ofstream fout("B-large-practice.out");
	char line[2001];
	char temp;
	int n;
	file.getline(line, 4);
	n=atoi(line);
	for (int i = 1; i <= n; ++i)
	{
		file.getline(line, 2001, '\n');
		int j = 0;
		int start;
		while (line[j] != '\0')
		{
			start = j;//某一单词的第一个字符
			while (line[j] != '\0' && line[j] != ' ')
				j++;
			//j现在指向空格了，从start到j-1单词作逆序
			for (int i = start; i <= (start + j - 1) / 2; ++i)
			{
				temp = line[i];
				line[i] = line[j - 1 +start- i];
				line[j - 1 + start - i] = temp;
			}
			if (line[j] == '\0')
				break;
			//如果j不是空，那j指向的就是空格，自加一下
			j++;
		}
		//从0到j-1再做一次反序
		for (int i = 0; i <= (j - 1) / 2; ++i)
		{
			temp = line[i];
			line[i] = line[j - 1 - i];
			line[j - 1 - i] = temp;
		}
		fout << "Case #"<<i<<": "<< line << endl;
	}
}