/*
Leetcode 239. Sliding Window Maximum
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.

Follow up:
Could you solve it in linear time?
*/

#include <cstdlib>
#include <vector>
#include <stack>
#include <deque>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		std::vector<int> v;
		int n = nums.size();
        if (n == 0) return v;
        deque<int> queue;
        // build the queue from [0,k - 1]
        for (int i = 0; i < k; ++i) {
        	while (queue.empty() == false && nums[queue.back()] < nums[i])
        		queue.pop_back();
        	queue.push_back(i);
        }
        v.push_back(nums[queue.front()]);
        // manage the queue from [k, n - 1]
        for (int i = k; i < n; ++i) {
        	while (queue.empty() == false && nums[queue.back()] < nums[i])
        		queue.pop_back();
        	if (queue.empty() == false && queue.front() == i - k) queue.pop_front();
        	queue.push_back(i);
        	v.push_back(nums[queue.front()]);
        }
        return v;
    }
};

void test0() {
	Solution sol;
	std::vector<int> v = {1};
	vector<int> vexpected = {1};
	std::vector<int> vm = sol.maxSlidingWindow(v,1);
	assert (vm == vexpected);
}

void test0_1() {
	Solution sol;
	std::vector<int> v = {2,1,2,3};
	vector<int> vexpected = {2,2,3};
	std::vector<int> vm = sol.maxSlidingWindow(v,2);
	assert (vm == vexpected);
}

void test1() {
	Solution sol;
	std::vector<int> v = {1,2,3,4,5};
	vector<int> vexpected = {2,3,4,5};
	std::vector<int> vm = sol.maxSlidingWindow(v,2);
	assert (vm == vexpected);
}

void test1_1() {
	Solution sol;
	std::vector<int> v = {1,3,-1,-3,5,3,6,7};
	vector<int> vexpected = {3,3,5,5,6,7};
	std::vector<int> vm = sol.maxSlidingWindow(v,3);
	assert (vm == vexpected);
}

void test2() {
	Solution sol;
	std::vector<int> v = {10,9,8,-1,10,5,4,9,8,10,11};
	vector<int> vexpected = {10,10,10,10,10,9,10,11};
	std::vector<int> vm = sol.maxSlidingWindow(v,4);
	assert (vm == vexpected);
}

void test3() {
	Solution sol;
	std::vector<int> v = {1,9,9,9,9,9,9,8};
	vector<int> vexpected = {9,9,9,9,9,9,9};
	std::vector<int> vm = sol.maxSlidingWindow(v,2);
	assert (vm == vexpected);
}

void test4() {
	Solution sol;
	std::vector<int> v = {8,9,9,9,9,9,9};
	vector<int> vexpected = {8,9,9,9,9,9,9};
	std::vector<int> vm = sol.maxSlidingWindow(v,1);
	assert (vm == vexpected);
}

void test5() {
	Solution sol;
	std::vector<int> v = {8,9,9,9,9,9,8};
	vector<int> vexpected = {9,9,9};
	std::vector<int> vm = sol.maxSlidingWindow(v,5);
	assert (vm == vexpected);
}

void test6() {
	Solution sol;
	std::vector<int> v = {9,10,9,-7,-4,-8,2,-6};
	vector<int> vexpected = {10,10,9,2};
	std::vector<int> vm = sol.maxSlidingWindow(v,5);
	assert (vm == vexpected);
}

int main() {
	test0();
	test1();
	test1_1();
	test2();
	test3();
	test4();
	test5();
	test6();
	/*test7();*/
	return 0;
}
