#include <iostream>
#include <vector>
using namespace std;
/*Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.*/
int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1)
	{
		return 0;
	}
	vector<int> earns(prices.size(),0);
	int min = prices[0];
	for (int i = 1; i < prices.size(); i++)
	{
		if (prices[i] < min)
		{
			min = prices[i];
		}
		earns[i] = prices[i] - min;
	}
	int max = earns[0];
	for (int i = 1; i < earns.size(); i++)
	{
		if (earns[i] > max)
		{
			max = earns[i];
		}
	}
	return max;
}
int maxProfit_1(vector<int>& prices) {
	if (prices.size() <= 1)
	{
		return 0;
	}
	int max = INT_MIN;
	for (int i = 0; i < prices.size(); i++)
	{
		for (int j = i + 1; j < prices.size(); j++)
		{
			if (prices[j] - prices[i] > max)
			{
				max = prices[j] - prices[i];
			}
		}
	}
	return max < 0 ? 0 : max;
}
int main()
{
	vector<int> nums;
	//[7, 1, 5, 3, 6, 4]
	//nums.push_back(7);
	//nums.push_back(1);
	//nums.push_back(5);
	//nums.push_back(3);
	//nums.push_back(6);
	//nums.push_back(4);
	//[7, 6, 4, 3, 1]
	//nums.push_back(7);
	//nums.push_back(6);
	//nums.push_back(5);
	//nums.push_back(4);
	//nums.push_back(3);
	//nums.push_back(1);
	//[2,1,2,1,0,1,2]
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	//
	cout << maxProfit(nums) << endl;
	getchar();
	return 0;
}
