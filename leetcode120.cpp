#include <iostream>
#include <vector>
#include <string>
using namespace std;

//法一：从上到下， 下一行的结果根据上一行的路径累计和而计算。 
//triangle[i][j] += min(triangle[i - 1[j - 1], triangle[i - 1][j]) ，这样需要处理j = 0和j = 最大值。
//法二：从下往上，每一行的结果根据下面一行的路基累计和而计算。
//triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1])
int minimumTotal(vector<vector<int>>& triangle) {
	for (int i = triangle.size() - 2; i >= 0; i--)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			triangle[i][j] += triangle[i + 1][j] > triangle[i + 1][j + 1] ? triangle[i + 1][j + 1] : triangle[i + 1][j];
		}
	}
	return triangle[0][0];
}

int main()
{
	vector<vector<int>> triangle;
	vector<int> temp;
	temp.push_back(2);
	triangle.push_back(temp);
	temp.clear();
	temp.push_back(3);
	temp.push_back(4);
	triangle.push_back(temp);
	temp.clear();
	temp.push_back(5);
	temp.push_back(6);
	temp.push_back(7);
	triangle.push_back(temp);
	temp.clear();
	temp.push_back(4);
	temp.push_back(1);
	temp.push_back(8);
	temp.push_back(3);
	triangle.push_back(temp);
	//[[-1],[2,3],[1,-1,-3]]
	cout << minimumTotal(triangle) << endl;
	getchar();
}
