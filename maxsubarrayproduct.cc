/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question.
*/

#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
    
		int n = nums.size();
        int maxPrd = nums[0];
        int minPrd = nums[0];
        int mx = 0, mn = 0;

        int res = 0;
        res = max (maxPrd, minPrd);
        for (int i = 1; i < n; ++i) {
        	mx = maxPrd;
        	mn = minPrd;
        	maxPrd = max (max(nums[i], mx * nums[i]), mn * nums[i]);
        	minPrd = min (min(nums[i], mn * nums[i]), mx * nums[i]);
        	
        	res = max(res, max (minPrd, maxPrd));
        	//cout << minPrd << " " << maxPrd << " " << res << endl;
        }
        return res;
    }
 };

void test0() {
	int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxProduct(v);
	assert (res == 960);
}

void test1() {
	int arr[] = {-1,-2,3,-1,-10,-11};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxProduct(v);
	assert (res == 660);
}

void test2() {
	int arr[] = {-2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxProduct(v);
	assert (res == -2);
}

void test3() {
	int arr[] = {2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxProduct(v);
	assert (res == 2);
}

void test4() {
	int arr[] = {-2, 1};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxProduct(v);
	assert (res == 1);
}

void test5() {
	int arr[] = {-2,1,0,1,5,-1,-2,1,-5,4};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxProduct(v);
	assert (res == 40);
}

void test6() {
	int arr[] = {2,3,-2,4};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.maxProduct(v);
	assert (res == 6);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}