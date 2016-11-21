/*************************************************************************
	> File Name: leetcode463.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 20 Nov 2016 10:02:37 PM PST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

//思路：
//按照行扫描一遍只计算行的周长
//按照列在扫描一遍只计算列的周长
//两个相加即为整个的周长
int islandPerimeter(vector<vector<int> >& grid) {
    if(grid.size() <= 0)
    {
        return 0;
    }
    int result = 0;
    int last = 0;
    for(int i = 0 ; i < grid.size();i++)
    {
        for(int j = 0;j < grid[i].size();j++)
        {
            //当last = 1 grid[i][j] = 0是进行计算
            //或者grid[i].size() -1 == j是进行计算
            if((last == 1&&grid[i][j] == 0)||(grid[i][j] == 1 && grid[i].size() -1 == j))
            {
                result += 2;
            }
            last = grid[i][j];
        }
        last = 0;
    }
    last = 0;
    for(int i = 0; i < grid[0].size();i++)
    {
        for(int j = 0; j < grid.size();j++)
        {
            if((last == 1 && grid[j][i] == 0)||(grid[j][i] == 1 && grid.size() -1 == j))
            {
                result += 2;
            }
            last = grid[j][i];
        }
        last = 0;
    }
    return result;
}
int main()
{
    //[[0,1,0,0],
    // [1,1,1,0],
    // [0,1,0,0],
    // [1,1,0,0]]
    vector<vector<int> > grid;
    /*vector<int> row;
    row.push_back(0);
    row.push_back(1);
    row.push_back(1);
    row.push_back(0);
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    row.push_back(0);
    row.push_back(1);
    grid.push_back(row);*/
    vector<int> first;
    first.push_back(0);
    first.push_back(1);
    first.push_back(0);
    first.push_back(0);
    vector<int> sec;
    sec.push_back(1);
    sec.push_back(1);
    sec.push_back(1);
    sec.push_back(0);
    vector<int> third;
    third.push_back(0);
    third.push_back(1);
    third.push_back(0);
    third.push_back(0);
    vector<int> forth;
    forth.push_back(1);
    forth.push_back(1);
    forth.push_back(0);
    forth.push_back(0);
    grid.push_back(first);
    grid.push_back(sec);
    grid.push_back(third);
    grid.push_back(forth);
    cout << islandPerimeter(grid) << endl;
}
