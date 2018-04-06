/*
Leetcode: 229 Majority element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

*/

#include <vector>
#include <unordered_map>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> counts;
        vector<int> elems;
        for (int i = 0; i < n; ++i)
            counts[nums[i]] += 1;
        for (int i = 0; i < n; ++i) {
            if (counts[nums[i]] > n/3) elems.push_back(nums[i]);
        }
        return elems;
    }
};

void printVector(std::vector<int>& v) {
    cout << "printVector\n";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void test1() {
	Solution s;
	vector<int> nums = {1,2,1,2,1,2,1};
	vector<int> majorityElems = s.majorityElement(nums);
	printVector(majorityElems);
	assert();
}

int main() {
	test1();
	return 0;
}
