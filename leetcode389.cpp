/*************************************************************************
	> File Name: leetcode389.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 30 Aug 2016 06:51:05 PM PDT
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
using namespace std;

char findTheDifference(string s, string t) {
    map<char,int> t_map;
    char c;
    for(int i = 0 ; i < t.size();i++)
    {
        if(t_map.find(t[i]) == t_map.end())
        {
            t_map[t[i]] = 1;
        }
        else
        {
            t_map[t[i]]++;
        }
    }
    for(int i = 0; i < s.size();i++)
    {
        t_map[s[i]]--;
    }
    for(map<char,int>::iterator it = t_map.begin();it != t_map.end();it++)
    {
        if(it->second != 0)
        {
            c = it->first;
            break;
        }
    }
    return c;
}
char findTheDifference_2(string s, string t) {
    //不仅要考虑是否种类上的不一样也要考虑个数上的不一样的问题
    char c;
    map<char,int> s_map;
    for(int i = 0 ;i < s.size(); i++)
    {
        if(s_map.find(s[i]) == s_map.end())
        {
            s_map[s[i]] = 1;
        }
        else
        {
            s_map[s[i]]++;
        }
    }
    map<char,int> t_map;
    for(int i = 0 ; i < t.size(); i++)
    {
        if(t_map.find(t[i]) == t_map.end())
        {
            t_map[t[i]] = 1;
        }
        else
        {
            t_map[t[i]]++;
        }
    }
    for(map<char,int>::iterator it = t_map.begin(); it != t_map.end();it++)
    {
        if(s_map.find(it->first) != s_map.end())
        {
            if(s_map[it->first] != it->second)
            {
                c = it->first;
                break;
            }
        }
        else
        {
            c = it->first;
            break;
        }
    }
    return c;
}
int main()
{
    cout << findTheDifference("abcd","abcde") <<endl;
    cout << findTheDifference("ymbgaraibkfmvocpizdydugvalagaivdbfsfbepeyccqfepzvtpyxtbadkhmwmoswrcxnargtlswqemafandgkmydtimuzvjwxvlfwlhvkrgcsithaqlcvrihrwqkpjdhgfgreqoxzfvhjzojhghfwbvpfzectwwhexthbsndovxejsntmjihchaotbgcysfdaojkjldprwyrnischrgmtvjcorypvopfmegizfkvudubnejzfqffvgdoxohuinkyygbdzmshvyqyhsozwvlhevfepdvafgkqpkmcsikfyxczcovrmwqxxbnhfzcjjcpgzjjfateajnnvlbwhyppdleahgaypxidkpwmfqwqyofwdqgxhjaxvyrzupfwesmxbjszolgwqvfiozofncbohduqgiswuiyddmwlwubetyaummenkdfptjczxemryuotrrymrfdxtrebpbjtpnuhsbnovhectpjhfhahbqrfbyxggobsweefcwxpqsspyssrmdhuelkkvyjxswjwofngpwfxvknkjviiavorwyfzlnktmfwxkvwkrwdcxjfzikdyswsuxegmhtnxjraqrdchaauazfhtklxsksbhwgjphgbasfnlwqwukprgvihntsyymdrfovaszjywuqygpvjtvlsvvqbvzsmgweiayhlubnbsitvfxawhfmfiatxvqrcwjshvovxknnxnyyfexqycrlyksderlqarqhkxyaqwlwoqcribumrqjtelhwdvaiysgjlvksrfvjlcaiwrirtkkxbwgicyhvakxgdjwnwmubkiazdjkfmotglclqndqjxethoutvjchjbkoasnnfbgrnycucfpeovruguzumgmgddqwjgdvaujhyqsqtoexmnfuluaqbxoofvotvfoiexbnprrxptchmlctzgqtkivsilwgwgvpidpvasurraqfkcmxhdapjrlrnkbklwkrvoaziznlpor","qhxepbshlrhoecdaodgpousbzfcqjxulatciapuftffahhlmxbufgjuxstfjvljybfxnenlacmjqoymvamphpxnolwijwcecgwbcjhgdybfffwoygikvoecdggplfohemfypxfsvdrseyhmvkoovxhdvoavsqqbrsqrkqhbtmgwaurgisloqjixfwfvwtszcxwktkwesaxsmhsvlitegrlzkvfqoiiwxbzskzoewbkxtphapavbyvhzvgrrfriddnsrftfowhdanvhjvurhljmpxvpddxmzfgwwpkjrfgqptrmumoemhfpojnxzwlrxkcafvbhlwrapubhveattfifsmiounhqusvhywnxhwrgamgnesxmzliyzisqrwvkiyderyotxhwspqrrkeczjysfujvovsfcfouykcqyjoobfdgnlswfzjmyucaxuaslzwfnetekymrwbvponiaojdqnbmboldvvitamntwnyaeppjaohwkrisrlrgwcjqqgxeqerjrbapfzurcwxhcwzugcgnirkkrxdthtbmdqgvqxilllrsbwjhwqszrjtzyetwubdrlyakzxcveufvhqugyawvkivwonvmrgnchkzdysngqdibhkyboyftxcvvjoggecjsajbuqkjjxfvynrjsnvtfvgpgveycxidhhfauvjovmnbqgoxsafknluyimkczykwdgvqwlvvgdmufxdypwnajkncoynqticfetcdafvtqszuwfmrdggifokwmkgzuxnhncmnsstffqpqbplypapctctfhqpihavligbrutxmmygiyaklqtakdidvnvrjfteazeqmbgklrgrorudayokxptswwkcircwuhcavhdparjfkjypkyxhbgwxbkvpvrtzjaetahmxevmkhdfyidhrdeejapfbafwmdqjqszwnwzgclitdhlnkaiyldwkwwzvhyorgbysyjbxsspnjdewjxbhpsvj") <<endl;
}
