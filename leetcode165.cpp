/*************************************************************************
	> File Name: leetcode165.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Nov 2016 09:31:21 PM PST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int compareVersion(string version1, string version2) {
    int pos1 = version1.find('.',0);
    int pos2 = version2.find('.',0);
    cout << pos1 <<"-----"<< pos2<<endl;
    if(pos1 > pos2)
    {
        return 1;
    }
    else if(pos1 < pos2)
    {
        return -1;
    }
    else
    {
        for(int i = 0 ;i < pos1; i++)
        {
            if(version1[i] > version2[i])
            {
                return 1;
            }
            else if(version1[i] < version2[i])
            {
                return -1;
            }
        }
        int leftPos1 = version1.length() - pos1;
        int leftPos2 = version2.length() - pos2;
        if(leftPos1 > leftPos2)
        {
            return 1;
        }
        else if(leftPos1 < leftPos2)
        {
            return -1;
        }
        int len = leftPos1 > leftPos2 ? version2.length(): version1.length() ;
        for(int i = pos1+1;i < len ;i++)
        {
            if(version1[i] > version2[i])
            {
                return 1;
            }
            else if(version1[i] < version2[i])
            {
                return -1;
            }
        }
    }
    return 0;
}
int main()
{
    cout <<"(1.2,12.3),***"<<compareVersion("1.2","12.3") << endl;
    cout <<"(1.2,1.2),***"<<compareVersion("1.2","1.2") << endl;
    cout <<"(1.2,1.21),***"<<compareVersion("1.2","1.21") << endl;
    cout <<"(1.2,1.12),***"<<compareVersion("1.2","1.12") << endl;
    cout <<"(1.2,1.1),***"<<compareVersion("1.2","1.1") << endl;
}
