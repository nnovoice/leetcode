/*
Leetcode 136. Single Number
Given an array of integers, every element appears twice except for one. Find that single one.
*/

#include <unordered_set>
#include <vector>
#include <climits>
#include <cassert>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int n = nums.size();
		if (n == 0) return 0;
		unordered_set<int> eset;
		for (int i = 0; i < n; ++i) {
			if (eset.find(nums[i]) != eset.end())
				eset.erase(nums[i]);
			else
				eset.insert(nums[i]);
		}
		unordered_set<int>::iterator it = eset.begin();
		return *it;
    }
};

void test0() {
	Solution sol;
	int arr[] = {};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.singleNumber(v);
	assert (res == 0);
}

void test1() {
	Solution sol;
	int arr[] = {1};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.singleNumber(v);
	assert (res == 1);
}

void test2() {
	Solution sol;
	int arr[] = {1,1,2,3,4,5,2,3,4};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	int res = sol.singleNumber(v);
	assert (res == 5);
}

int main() {
	test0();
	test1();
	test2();
	/*test3();
	test4();
	test5();*/
	/*test6();
	test7();*/
	return 0;
}
