#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool canConstruct(string ransomNote, string magazine) {
	if (ransomNote.size() <= 0)
	{
		return true;
	}
	vector< int> ransomeNote_vec(26,0);
	vector< int> magazine_vec(26,0);
	for (int i = 0; i < ransomNote.size(); i++)
	{
		ransomeNote_vec[ransomNote[i] - 'a']++;
	}
	for (int i = 0; i < magazine.size(); i++)
	{
		magazine_vec[magazine[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (ransomeNote_vec[i] > magazine_vec[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{

	cout << canConstruct("a", "b") << endl;
	cout <<	canConstruct("aa", "ab") << endl;
	cout << canConstruct("aa", "aab") << endl;
	cout << canConstruct("fffbfg", "effjfggbffjdgbjjhhdegh") << endl;
	cout << canConstruct("bjaajgea", "affhiiicabhbdchbidghccijjbfjfhjeddgggbajhidhjchiedhdibgeaecffbbbefiabjdhggihccec") << endl;
	getchar();
}
