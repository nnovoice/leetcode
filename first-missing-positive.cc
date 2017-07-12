/*
Leetcode: 41. First Missing Positive
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> found;
        int max_num = 1;
        int l = 0, g = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
            	found.insert(nums[i]);
            	if (nums[i] > max_num) max_num = nums[i];
            }
        }
        for (int i = 1; i <= max_num + 1; ++i) {
        	if (found.find(i) == found.end()) return i;
        }
        return -1;
    }
};

void printArray(vector<int>& v) {
	int n = v.size();
	for (int i = 0; i < n; ++i)
		cout << v[i] << " ";
	cout << endl;
}

void test0() {
	Solution sol;
	std::vector<int> v1 = {};
	int res = sol.firstMissingPositive(v1);
	cout << res << endl;
	assert (res == 1);
}

void test1() {
	Solution sol;
	std::vector<int> v1 = {-2,-1,0,1};
	int res = sol.firstMissingPositive(v1);
	assert (res == 2);
}

void test1_1() {
	Solution sol;
	std::vector<int> v1 = {1,2,3,4,5};
	int res = sol.firstMissingPositive(v1);
	assert (res == 6);
}

void test1_2() {
	Solution sol;
	std::vector<int> v1 = {0,1,2,3,4,5,6};
	int res = sol.firstMissingPositive(v1);
	assert (res == 7);
}

void test2() {
	Solution sol;
	std::vector<int> v1 = {0,1,2,4,5,6};
	int res = sol.firstMissingPositive(v1);
	assert (res == 3);
}

void test3() {
	Solution sol;
	std::vector<int> v1 = {-1,0,4,9,10,1,3,2};
	int res = sol.firstMissingPositive(v1);
	assert (res == 5);
}

void test4() {
	Solution sol;
	std::vector<int> v1 = {-1,0,4,9,10,1,3};
	int res = sol.firstMissingPositive(v1);
	assert (res == 2);
}

void test5() {
	Solution sol;
	std::vector<int> v1 = {-1,2,100,5,0,4,9,10,1,3};
	int res = sol.firstMissingPositive(v1);
	assert (res == 6);
}

int main() {
	test0();
	test1();
	test1_1();
	test1_2();
	test2();
	test3();
	test4();
	test5();
	/*test6();
	test7();*/
	return 0;
}
