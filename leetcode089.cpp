/*************************************************************************
	> File Name: leetcode089.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Aug 2016 06:22:32 PM PDT
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
/*
*自然二进制码转换为格雷码：g0 = b0; gi = bi bi􀀀1
保留自然二进制码的最高位作为格雷码的最高位，格雷码次高位为二进制码的高位与次高位异
或，其余各位与次高位的求法类似。例如，将自然二进制码1001，转换为格雷码的过程是：保留最
高位；然后将第1 位的1 和第2 位的0 异或，得到1，作为格雷码的第2 位；将第2 位的0 和第3 位
的0 异或，得到0，作为格雷码的第3 位；将第3 位的0 和第4 位的1 异或，得到1，作为格雷码的
第4 位，最终，格雷码为1101。
* */
vector<int> grayCode(int n) {
    vector<int> result;
    int count = 1 << n;
    for(int i = 0 ; i < count ; i++)
    {
        result.push_back(i^(i>>1));
    }
    return result;
}
int main()
{
    vector<int> data = grayCode(3);
    for(int i = 0 ; i < data.size(); i++)
    {
        cout << data[i]<<endl;
    }
}
