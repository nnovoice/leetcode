/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

void printVector(vector<int>& v) {
	for (int a : v) 
		cout << a << " ";
	cout << endl;
}

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0 || k == 0) return;
		k = k % n;
		for (int i = 0, j = n - 1; i < j; ++i, --j)
			std::swap(nums[i], nums[j]);
		//printVector(nums);
		for (int i = 0, j = k - 1; i < j; ++i, --j)
			std::swap(nums[i], nums[j]);
		//printVector(nums);
		for (int i = k, j = n - 1; i < j; ++i, --j)
			std::swap(nums[i], nums[j]);
		//printVector(nums);
    }
};	

void test0() {
	std::vector<int> v = {10, 11, 12, 13, 14, 15, 16};
	std::vector<int> v1 = {14, 15, 16, 10, 11, 12, 13};
	Solution sol;
	sol.rotate(v, 3);
	assert(v == v1);
}

void test1() {
	std::vector<int> v = {10, 11, 12, 13, 14, 15, 16};
	std::vector<int> v1 = {13, 14, 15, 16, 10, 11, 12};
	Solution sol;
	sol.rotate(v, 4);
	assert(v == v1);
}

void test2() {
	std::vector<int> v = {10, 11};
	std::vector<int> v1 = {11, 10};
	Solution sol;
	sol.rotate(v, 1);
	assert(v == v1);
}

void test3() {
	std::vector<int> v = {10, 11, 12, 13, 14, 15, 16};
	std::vector<int> v1 = {10, 11, 12, 13, 14, 15, 16};
	Solution sol;
	sol.rotate(v, 7);
	assert(v == v1);
}

void test4() {
	std::vector<int> v = {10, 11, 12, 13, 14, 15, 16};
	std::vector<int> v1 = {15, 16, 10, 11, 12, 13, 14};
	Solution sol;
	sol.rotate(v, 2);
	assert(v == v1);
}

void test5() {
	std::vector<int> v = {1,2,3,4,5,6};
	std::vector<int> v1 = {5,6,1,2,3,4};
	Solution sol;
	sol.rotate(v, 2);
	assert(v == v1);
}

void test6() {
	std::vector<int> v = {1,2,3,4,5,6};
	std::vector<int> v1 = {1,2,3,4,5,6};
	Solution sol;
	sol.rotate(v, 6);
	assert(v == v1);
}

void test7() {
	std::vector<int> v = {10, 11, 12, 13, 14, 15, 16};
	std::vector<int> v1 = {13,14,15,16,10,11,12};
	Solution sol;
	sol.rotate(v, 11);
	assert(v == v1);
}

void test8() {
	std::vector<int> v = {10, 11};
	std::vector<int> v1 = {11, 10};
	Solution sol;
	sol.rotate(v, 3);
	assert(v == v1);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	return 0;
}