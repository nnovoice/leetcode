/*
Leetcode: 300. Longest increasing subsequence.
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?


*/
#include <vector>
//#include <stack>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp (n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; ++i) {
        	for (int j = i - 1; j >= 0; --j)
	        	if (nums[i] > nums[j]) {
	        		dp[i] = max(dp[i], dp[j] + 1);
        	}
        	maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

void test0() {
	Solution sol;
	int arr[] = {};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.lengthOfLIS(v);
	assert (res == 0);
}

void test1() {
	Solution sol;
	int arr[] = {5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.lengthOfLIS(v);
	assert (res == 1);
}

void test2() {
	Solution sol;
	int arr[] = {1,2,3,4,5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.lengthOfLIS(v);
	cout << res << endl;
	assert (res == 5);
}

void test3() {
	Solution sol;
	int arr[] = {5,4,3,2,1};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.lengthOfLIS(v);
	assert (res == 1);
}

void test4() {
	Solution sol;
	int arr[] = {7,1,5,6,2,8,3,9};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.lengthOfLIS(v);
	assert (res == 5);
}

void test5() {
	Solution sol;
	int arr[] = {7,1,5,5,6,2,8,3,9};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.lengthOfLIS(v);
	assert (res == 5);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}
