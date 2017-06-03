#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount + 1, INT_MIN);
        sort(coins.begin(), coins.end());
        int n = coins.size();
        dp[0] = 0;
        int m = INT_MAX;
        for (int val = 1; val <= amount; ++val) {
        	m = INT_MAX;
        	for (int j = 0; j < n; ++j) {
        		if (coins[j] > val) break;
        		if (val < coins[j]) break;
        		if (dp[val - coins[j]] == INT_MIN) continue;
        		m = min(m, 1 + dp[val - coins[j]]);
        	}
        	if (m > 0 && m != INT_MAX) dp[val] = m;
        }
        return (dp[amount] < 0) ? -1 : dp[amount];
    }
};

void test0() {
	Solution sol;
	int arr[] = {1,3,5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.coinChange(v, 5);
	assert (res == 1);
}

void test1() {
	Solution sol;
	int arr[] = {2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.coinChange(v, 5);
	cout << "res=" << res << endl;
	assert (res == -1);
}

void test2() {
	Solution sol;
	int arr[] = {1,2,3,4,5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.coinChange(v, 15);
	assert (res == 3);
}

void test3() {
	Solution sol;
	int arr[] = {1,2,3,4};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.coinChange(v, 101);
	assert (res == 26);
}

void test4() {
	Solution sol;
	int arr[] = {474,83,404,3};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.coinChange(v, 101);
	cout << "res=" << res << endl;
	assert (res == 8);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	//test5();
	return 0;
}