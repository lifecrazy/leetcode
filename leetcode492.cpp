#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> constructRectangle(int area) {
	vector<int> result;
	if (area == 1)
	{
		result.push_back(1);
		result.push_back(1);
		return result;
	}
	vector<int> last;
	int L;
	for (int i = 1; i <= area / 2; i++)
	{
		if (area % i == 0)
		{
			L = area / i;
			cout << L << "*****" << i << endl;
			if (result.size() > 0)
			{
				if (L - i >= 0 && L - i < last[0] - last[1])
				{
					result.clear();
					result.push_back(L);
					result.push_back(i);
				}
			}
			else
			{
				result.push_back(L);
				result.push_back(i);
			}
			last.clear();
			last.push_back(L);
			last.push_back(i);
		}
	}
	return result;
}
int main()
{
	//vector<int> result = constructRectangle(6);
	//for (int i = 0; i < result.size(); i++)
	//{
	//	cout << result[i] << "\t";
	//}
	//cout << endl;

	getchar();
}
