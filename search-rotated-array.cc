/*
Leetcode 33. Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.


*/
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;

        int low = 0, mid = 0, high = n - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            //cout << "num[" << mid << "]= " << nums[mid] << "target=" << target << endl;
            if (nums[mid] == target) return mid;
            if (nums[mid] > nums[high] && (target > nums[mid] || target <= nums[high]))
                low = mid + 1;
            else {
                if (nums[low] > nums[mid] && (target >= nums[low] || target < nums[mid]))
                    high = mid - 1;
                else if (target > nums[mid]) 
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;        
    }
};

void test0() {
	Solution sol;
	int arr[] = {1,3,5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.search(v, 5);
	assert (res == 1);
}

void test1() {
	Solution sol;
	int arr[] = {2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.search(v, 5);
	cout << "res=" << res << endl;
	assert (res == -1);
}

void test2() {
	Solution sol;
	int arr[] = {1,2,3,4,5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.search(v, 15);
	assert (res == 3);
}

void test3() {
	Solution sol;
	int arr[] = {1,2,3,4};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.search(v, 101);
	assert (res == 26);
}

void test4() {
	Solution sol;
	int arr[] = {474,83,404,3};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.search(v, 264);
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
