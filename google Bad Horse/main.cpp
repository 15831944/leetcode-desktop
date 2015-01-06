#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;

//2着色问题
#define MAXPEOPLE 230
int matrix[MAXPEOPLE][MAXPEOPLE];
int color[MAXPEOPLE];

void init()
{
	for (int i = 0; i < MAXPEOPLE; ++i)
	{
		for (int j = 0; j < MAXPEOPLE; ++j)
			matrix[i][j] = 0;
	}
		
	for (int i = 0; i < MAXPEOPLE; ++i)//初始染色为-1
		color[i] = -1;
}

//判断能否成功2着色
bool dfs(int currentpoint, int lastpoint)
{
	if (currentpoint > lastpoint)
		return true;//出口
	for (int colo = 1; colo <= 2; ++colo)
	{
		color[currentpoint] = colo;
		//检查当currentpoint涂色为colo时，与邻居是否有相同的
		bool flag = false;//没有相同的
		for (int nei = 0; nei <= lastpoint; ++nei)
		{
			if (matrix[currentpoint][nei] == 1 && color[nei] == color[currentpoint])
			{
				flag = true;
				break;
			}
		}

		if (!flag && dfs(currentpoint + 1, lastpoint))
			return true;

		//注意回溯
		color[currentpoint] = -1;
	}
	//尝试了所有颜色还没有出去true，该路径不通
	return false;
}

int main()
{
	int t;
	int m;
	string name1;
	string name2;
	int i1;
	int i2;
	ifstream infile("E:\\POJ\\leetcode\\google Bad Horse\\A-small-practice-2.in");
	ofstream outfile("E:\\POJ\\leetcode\\google Bad Horse\\A-small-practice-2.out");
	infile >> t;
	for (int i = 1; i <= t;i++)
	{
		init();
		unordered_map<string, int> nametoint;
		infile >> m;
		while( m-- )//m条边
		{
			infile >> name1 >> name2;
			if (nametoint.find(name1) != nametoint.end())
				i1 = nametoint[name1];
			else
			{
				i1 = nametoint.size();
				nametoint[name1] = i1;
			}
			if (nametoint.find(name2) != nametoint.end())
				i2 = nametoint[name2];
			else
			{
				i2 = nametoint.size();
				nametoint[name2] = i2;
			}
			matrix[i1][i2] = matrix[i2][i1] = 1;
		}

		//把图构造完成，开始对图进行2着色
		if (dfs(0, nametoint.size()-1))
			outfile << "Case #" << i << ": Yes" << endl;
		else
			outfile << "Case #" << i << ": No" << endl;
	}
	infile.close();
	outfile.close();
	return 0;
}