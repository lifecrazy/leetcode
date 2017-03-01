#include <iostream>
#include <vector>
#include <string>
using namespace std;

string findLongestWord(string s, vector<string>& d) {
	if (d.size() <= 0)
	{
		return "";
	}
	vector<int> res(d.size(), -1);
	bool flag = false;
	for (int i = 0; i < d.size(); i++)
	{
		int index = 0;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == d[i][index])
			{
				index++;
			}
			if (index == d[i].size())
			{
				flag = true;
				res[i] = index;
				break;
			}
		}
	}
	if (!flag)
	{
		return "";
	}
	int max = INT_MIN;
	int max_index = 0;
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] > max)
		{
			max = res[i];
			max_index = i;
		}
		else if (res[i] == max)
		{
			int k = 0;
			while (k < d[max_index].size())
			{
				if (d[i][k] < d[max_index][k])
				{
					max_index = i;
					break;
				}
				else if (d[i][k] > d[max_index][k])
				{
					break;
				}
				k++;
			}
		}
	}
	return d[max_index];
}
int main()
{
	//TreeNode* root = new TreeNode(1);
	//TreeNode* first = new TreeNode(5);
	//TreeNode* sec = new TreeNode(3);
	//root->right = sec;
	//first->left = first;
	//cout << getMinimumDifference(root) << endl;
	/*"abpcplea"
["ale","apple","monkey","plea"]*/
	//string s = "abpcplea";
	//vector<string> d;
	//d.push_back("ale");
	//d.push_back("apple");
	//d.push_back("monkey");
	//d.push_back("plea");
	//d.push_back("a");
	//d.push_back("b");
	//d.push_back("c");
	//"bab"
	//	["ba", "ab", "a", "b"]
	//string s = "bab";
	//vector<string> d;
	//d.push_back("ba");
	//d.push_back("ab");
	//d.push_back("a");
	//d.push_back("b");
	/*"apple"
		["zxc", "vbn"]*/
	//string s = "apple";
	//vector<string> d;
	//d.push_back("zxc");
	//d.push_back("vbn");
	/*"wordgoodgoodgoodbestword"
["word","good","best","good"]*/
string s = "wordgoodgoodgoodbestword";
vector<string> d;
d.push_back("word");
d.push_back("good");
d.push_back("best");
d.push_back("good");
	cout << findLongestWord(s, d) << endl;
	getchar();
	return 0;
}
