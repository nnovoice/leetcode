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
#include <climits>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <cassert>
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
    std::vector<int> v = {};
    int res = sol.search(v, 0);
    assert (res == -1);
}

void test1() {
    Solution sol;
    std::vector<int> v = {-1};
    int res = sol.search(v, -1);
    assert (res == 0);
}

void test1_1() {
    Solution sol;
    std::vector<int> v = {5};
    int res = sol.search(v, 1);
    assert (res == -1);
}

void test2() {
    Solution sol;
    std::vector<int> v = {1,2,3,4,5};
    int res = sol.search(v, 1);
    assert (res == 0);
}

void test3() {
    Solution sol;
    std::vector<int> v = {1,3,5,7,9,11};
    int res = sol.search(v, 11);
    assert (res == 5);
}

void test4() {
    Solution sol;
    std::vector<int> v = {7,9,11,1,3,5};
    int res = sol.search(v, 1);
    assert (res == 3);
}

void test5() {
    Solution sol;
    std::vector<int> v = {4,6,8,10,0,2};
    int res = sol.search(v, 6);
    cout << "test5=" << res << endl;
    assert (res == 1);
}

void test6() {
    Solution sol;
    std::vector<int> v = {2,4,6,8,10,0};
    int res = sol.search(v, 0);
    assert (res == 5);
}

void test7() {
    cout << "test7 begins:" << endl;
    std::vector<int> v = {4,6,8,10,0,2};
    Solution sol;
    int res = sol.search(v, 2);
    cout << "test7=" << res << endl;
    assert (res == 5);
}

void test8() {
    std::vector<int> v = {5,6,7,8,9,10,0,1,2,3,4};
    //std::vector<int> ev = {0,1,2,3,4,5,6,7,8,9,10};
    Solution sol;
    int n = v.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = sol.search(v, v[i]);
        assert (res == i);
    }
}

void test9() {
    std::vector<int> v = {3,5,7,9,11,-1,1};
    //std::vector<int> ev = {0,1,2,3,4,5,6,7,8,9,10};
    Solution sol;
    int n = v.size();
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = sol.search(v, v[i]);
        assert (res == i);
    }
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
    test7();
    test8();
    test9();
    return 0;
}
