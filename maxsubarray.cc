/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
*/

#include <vector>
#include <climits>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int n = nums.size();
        
        for (int i = 1; i < n; ++i) {
        	if (max < nums[i]) max = nums[i];
        }
        
        if (max < 0) return max;

        max = nums[0];
        int acc = nums[0];
        for (int i = 1; i < n; ++i) {
        	if ((acc + nums[i]) <= 0) acc = 0;
        	else acc += nums[i];
        	if (max < acc) max = acc;
        }
        return max;
    }
};

void test0() {
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxSubArray(v);
	assert (res == 6);
}

void test1() {
	int arr[] = {1,-2,2,3,-2,5,7};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxSubArray(v);
	assert (res == 15);
}

void test2() {
	int arr[] = {-2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxSubArray(v);
	assert (res == -2);
}

void test3() {
	int arr[] = {2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxSubArray(v);
	assert (res == 2);
}

void test4() {
	int arr[] = {-2, 1};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxSubArray(v);
	assert (res == 1);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	return 0;
}