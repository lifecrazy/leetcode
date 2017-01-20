#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Subscribe to see which companies asked this question*/
vector<string> restoreIpAddresses(string s) {
	vector<string> result;
	/*
	暴力搜索
	*/
	for (int i = 3; i > 0; i--)
	{
		for (int j = 3; j > 0; j--)
		{
			for (int k = 3; k > 0; k--)
			{
				for (int m = 3; m > 0; m--)
				{
					if (i + j + k + m == s.size())
					{
						int a = stoi(s.substr(0, i));
						int b = stoi(s.substr(i, j));
						int c = stoi(s.substr(i + j, k));
						int d = stoi(s.substr(i + j + k, m));
						if (a < 256 && b < 256 && c < 256 && d < 256)
						{
							string temp = to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
							if (s.size() + 3 == temp.size())
							{
								result.push_back(temp);
							}
						}
					}
				}
			}
		}
	}
	return result;
}

int main()
{
	string s = "25525511135";
	vector<string> result = restoreIpAddresses(s);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << endl;
	}
}
