/*************************************************************************
	> File Name: leetcode165.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Nov 2016 09:31:21 PM PST
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

int compareVersion(string version1, string version2) {
    int pos1 = version1.find('.',0);
    int pos2 = version2.find('.',0);
    if(pos1 == -1 && pos2 == -1)
    {
        int left1 = atoi(version1.c_str());
        int left2 = atoi(version2.c_str());
        if(left1 > left2)
        {
            return 1;
        }
        else if(left1 < left2)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    else if(pos1 != -1 && pos2 != -1)
    {
        int left1 = atoi(version1.substr(0,pos1).c_str());
        int left2 = atoi(version2.substr(0,pos2).c_str());
        if(left1 > left2)
        {
            return 1;
        }
        else if(left1 < left2)
        {
            return -1;
        }
        else
        {
            int right1 = atoi(version1.substr(pos1 + 1, version1.length() - pos1).c_str());
            int right2 = atoi(version2.substr(pos2 + 1, version2.length() - pos2).c_str());
            if(right1 > right2)
            {
                return 1;
            }
            else if(right1 < right2)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    {
        int left1 = 0;
        int left2 = 0;
        if(pos1 == -1)
        {
            left1 = atoi(version1.c_str());
            left2 = atoi(version2.substr(0,pos2).c_str());  
            if(left1 > left2)
            {
                return 1;
            }
            else if(left1 < left2)
            {
                return -1;
            }
            else
            {    
                int right = atoi(version2.substr(pos2 + 1, version2.length() - pos2).c_str());
                if(right > 0)
                {
                    return -1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            left2 = atoi(version2.c_str());
            left1 = atoi(version1.substr(0,pos1).c_str());
            if(left1 > left2)
            {
                return 1;
            }
            else if(left1 < left2)
            {
                return -1;
            }
            else
            {
     
                int right = atoi(version1.substr(pos1 + 1, version1.length() - pos1).c_str());
                if(right > 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
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
    cout <<"(1,1),***"<<compareVersion("1","1") << endl;
    cout <<"(01,1),***"<<compareVersion("01","1") << endl;
}
