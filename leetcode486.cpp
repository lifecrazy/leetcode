#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool PredictTheWinner(vector<int>& nums) {
	if (nums.size() == 1)
	{
		return true;
	}
	int even_sum = 0;
	int odd_sum = 0;
	if (nums.size() % 2 == 0)
	{
		return true;
	}
	else
	{
		bool flag = false;
		//排除第一个剩下的按照奇数或者偶数取和
		for (int i = 1; i < nums.size(); i++)
		{
			if (i % 2 == 0)
			{
				even_sum += nums[i];
			}
			else
			{
				odd_sum += nums[i];
			}
		}
		int tmp = even_sum > odd_sum ? even_sum - odd_sum : odd_sum - even_sum;
		if (tmp <= nums[0])
		{
			flag = true;
		}
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (i % 2 == 0)
			{
				even_sum += nums[i];
			}
			else
			{
				odd_sum += nums[i];
			}
		}
		 tmp = even_sum > odd_sum ? even_sum - odd_sum : odd_sum - even_sum;
		if (tmp <= nums[nums.size() - 1])
		{
			flag = true;
		}
		return flag;
	}

}
int main()
{
	//[9337301,0,2,2245036,4,1997658,5,2192224,960000,1261120,8824737,1,1161367,9479977,7,2356738,5,4,9]
	//vector<int> data;
	//data.push_back(9337301);
	//data.push_back(0);
	//data.push_back(2);
	//data.push_back(2245036);
	//data.push_back(4);
	//data.push_back(1997658);
	//data.push_back(5);
	//data.push_back(2192224);
	//data.push_back(960000);
	//data.push_back(1261120);
	//data.push_back(8824737);
	//data.push_back(1);
	//data.push_back(1161367);
	//data.push_back(9479977);
	//data.push_back(7);
	//data.push_back(2356738);
	//data.push_back(5);
	//data.push_back(4);
	//data.push_back(0);
	//cout << PredictTheWinner(data) << endl;
	getchar();
}
