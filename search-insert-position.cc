/*
Leetcode 35. Search Insert Position
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/
#include <vector>
#include <stack>
#include <climits>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return 0;
        int low = 0, high = n - 1, mid = 0;
        while (low <= high) {
        	mid = low + (high - low) / 2;
        	if (nums[mid] == target) return mid;
        	if (nums[mid] < target) low = mid + 1;
        	else high = mid - 1;
        }
        if (nums[mid] < target) return mid + 1;
        return mid;
    }
};

void test0() {
	Solution sol;
	int arr[] = {};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.searchInsert(v, 101);
	assert (res == 0);
}

void test1() {
	Solution sol;
	int arr[] = {5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.searchInsert(v, 4);
	assert (res == 0);
}

void test1_1() {
	Solution sol;
	int arr[] = {5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.searchInsert(v, 6);
	assert (res == 1);
}

void test2() {
	Solution sol;
	int arr[] = {1,2,3,4,5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.searchInsert(v, 6);
	assert (res == 5);
}

void test3() {
	Solution sol;
	int arr[] = {1,3,5,7,9,11};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.searchInsert(v, 2);
	assert (res == 1);
}

void test4() {
	Solution sol;
	int arr[] = {1,3,5,7,9,11};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.searchInsert(v, 12);
	assert (res == 6);
}

void test5() {
	Solution sol;
	int arr[] = {1,3,5,7,9,11};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.searchInsert(v,6);
	assert (res == 3);
}

int main() {
	test0();
	test1();
	test1_1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}
