/*
Given an array of n elements and a given target sum S and a number of elements M, find the elements
that sum to nearest S.

Assuming +ve numbers

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
        if (nums.size() == 0) return 1;
        unordered_set<int> missing, found;
        int l = 0, g = 0;
        for (int i = 0; i < nums.size(); ++i) {
            found.insert(nums[i]);
            if (nums[i] > 1) {
                l = nums[i] - 1;
                if (found.find(l) == found.end()) {
                    if (missing.find(l) == missing.end())
                        missing.insert(l);
                }
            }
            g = nums[i] + 1;
            if (found.find(g) == found.end()) {
                if (missing.find(g) == missing.end())
                    missing.insert(g);
            }
        }
        if (missing.size() > 0) {
            int min = INT_MAX;
            unordered_set<int>::iterator iter = missing.begin();
            for (; iter != missing.end(); ++iter)
                if (*iter < min) min = *iter;
            return min;
        }
        else {
            int max = INT_MIN;
            unordered_set<int>::iterator iter = found.begin();
            for (; iter != found.end(); ++iter) 
                if (*iter > max) max = *iter;
            return max + 1;
        }
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
	assert (res == 1);
}

void test1() {
	Solution sol;
	std::vector<int> v1 = {-2,-1,0,1};
	int res = sol.firstMissingPositive(v1);
	assert (res == 1);
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
