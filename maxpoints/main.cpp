#include <vector>
#include <iostream>
#include <hash_map>//���Ǳ�׼��
#include <map>
using namespace std;

 struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
 };
 
class Solution {
public:
    int maxPoints(vector<Point> &points) {
		if(points.size()<=2)
			return points.size();
		int max=0;
		double k;//б��
		for(std::vector<Point>::const_iterator it1 = points.begin(); it1 < points.end(); ++it1)//��it1�������ҿ�����м����ظ���б��
		{
			int maxi=0;//��it1�����ֱ�ߵ�������
			int samepoint=0;
			map<double,int> doublehash;
			int wuqiong=0;//б�������ĵ����
			for(vector<Point>::const_iterator it2 = it1+1; it2 < points.end(); ++it2)
			{//��it1��it2ȷ����ֱ��
				if(it2->x==it1->x)
				{
					if(it2->y==it1->y)
					{
						samepoint++;
						continue;
					}
					wuqiong++;
					if(wuqiong>maxi)
						maxi=wuqiong;
				}
				else
				{
					k=1.0*(it2->y-it1->y)/(it2->x-it1->x);
					if(doublehash.find(k) != doublehash.end())
						doublehash[k]++;
					else
						doublehash[k]=1;
					if(doublehash[k]>maxi)
						maxi=doublehash[k];
				}
			}
			maxi+=samepoint;
			if(max<maxi)
				max=maxi;
		}
		return max+1;
    }
};

int main()
{
	Solution test;
	vector<Point> p;
	Point p1(0,0);
	Point p2(1,1);
	Point p3(0,0);
	//Point p4(2,4);

	p.push_back(p1);
	p.push_back(p2);
	p.push_back(p3);
	//p.push_back(p4);
	cout<<test.maxPoints(p)<<endl;
}