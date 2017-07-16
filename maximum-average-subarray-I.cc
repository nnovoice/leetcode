/*
Leetcode: 56. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include <cassert>
using namespace std;


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_avg = -1 * numeric_limits<double>::max(), avg = 0.0;
        int sum = 0;
        int n = nums.size();
        
        if (k > n) k = nums.size();

        for (int i = 0; i < k; ++i) {
        	sum += nums[i];
        }
        
        avg = (double) sum / k;
        max_avg = max (max_avg, avg);

        for (int i = k; i < n; ++i) {
        	sum -= nums[i - k];
        	sum += nums[i];
        	avg = (double) sum / k;
        	max_avg = max (max_avg, avg);
        }

        return max_avg;
    }
};

void test0() {
	std::vector<int> v = {1,12,-5,-6,50,3};
	Solution sol;
	double res = sol.findMaxAverage(v, 4);
	cout << res << endl;
	assert(res == 12.75);
}

void test1() {
	std::vector<int> v = {5};
	Solution sol;
	double res = sol.findMaxAverage(v, 1);
	cout << res << endl;
	assert(res == 5.00);
}

void test2() {
	std::vector<int> v = {5, -1, 0};
	Solution sol;
	double res = sol.findMaxAverage(v, 4);
	cout << res << endl;
	//assert(res == 1.33);
}

void test3() {
	std::vector<int> v = {5, -1, 0};
	Solution sol;
	double res = sol.findMaxAverage(v, 3);
	cout << res << endl;
	//assert(res == 1.33);
}


int main() {
	test0();
	test1();
	test2();
	test3();
	return 0;
}