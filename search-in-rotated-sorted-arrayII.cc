/*
Leetcode 81. Search in Rotated Sorted Array II
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.

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
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;

        int low = 0, mid = 0, high = n - 1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            //cout << "num[" << mid << "]= " << nums[mid] << "target=" << target << endl;
            if (nums[mid] == target) return true;
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
        return false;        
    }
};

 void test0() {
    Solution sol;
    std::vector<int> v = {};
    bool res = sol.search(v, 0);
    assert (res == false);
}

void test1() {
    Solution sol;
    std::vector<int> v = {-1};
    bool res = sol.search(v, -1);
    assert (res == true);
}

void test1_0() {
    Solution sol;
    std::vector<int> v = {5};
    bool res = sol.search(v, 1);
    assert (res == false);
}

void test2() {
    Solution sol;
    std::vector<int> v = {1,1,2,2,2,3,3,3,3,3,4,4,5};
    bool res = sol.search(v, 1);
    assert (res == true);
}

void test3() {
    Solution sol;
    std::vector<int> v = {1,1,1,1,1,1,3,3,3,3,3,5,7,7,9,9,11,11,11};
    bool res = sol.search(v, 11);
    assert (res == true);
}

void test3_0() {
    Solution sol;
    std::vector<int> v = {1,1,1,1,1,1,3,3,3,3,3,5,7,7,9,9,11,11,11};
    bool res = sol.search(v, 5);
    assert (res == true);
}

void test3_1() {
    Solution sol;
    std::vector<int> v = {1,1,1,1,1,1,3,3,3,3,3,5,7,7,9,9,11,11,11};
    bool res = sol.search(v, 2);
    assert (res == false);
}

void test4() {
    Solution sol;
    std::vector<int> v = {7,7,7,9,9,9,9,9,9,11,11,11,11,11,1,1,1,1,3,3,5};
    bool res = sol.search(v, 5);
    assert (res == true);
}

void test4_0() {
    Solution sol;
    std::vector<int> v = {7,7,7,9,9,9,9,9,9,11,11,11,11,11,1,1,1,1,3,3,5};
    bool res = sol.search(v, 10);
    assert (res == false);
}

void test5() {
    Solution sol;
    std::vector<int> v = {4,4,4,6,8,10,0,2,2,2,4,4};
    bool res = sol.search(v, 6);
    cout << "test5=" << res << endl;
    assert (res == true);
}

void test6() {
    Solution sol;
    std::vector<int> v = {4,10,10,10,10,10,2,2,2,2,2,2,2,2,2,2,4};
    bool res = sol.search(v, 4);
    assert (res == true);
}

void test6_0() {
    Solution sol;
    std::vector<int> v = {4,10,10,10,10,10,2,2,2,2,2,2,2,2,2,2,4};
    bool res = sol.search(v, 1);
    assert (res == false);
}

void test7() {
    cout << "test7 begins:" << endl;
    std::vector<int> v = {4,6,8,10,0,2};
    Solution sol;
    bool res = sol.search(v, 2);
    cout << "test7=" << res << endl;
    assert (res == true);
}

void test8() {
    std::vector<int> v = {5,5,6,7,7,8,8,8,8,9,10,10,0,1,1,2,2,3,4};
    //std::vector<int> ev = {0,1,2,3,4,5,6,7,8,9,10};
    Solution sol;
    int n = v.size();
    bool res = false;
    for (int i = 0; i < n; ++i) {
        res = sol.search(v, v[i]);
        assert (res == true);
    }
}

void test8_0() {
    std::vector<int> v = {5,5,6,7,7,8,8,8,8,9,10,10,0,1,1,2,2,3,4};
    //std::vector<int> ev = {0,1,2,3,4,5,6,7,8,9,10};
    Solution sol;
    int n = v.size();
    bool res = false;
    res = sol.search(v, 0);
    assert (res == true);
}

void test9() {
    std::vector<int> v = {1,1,1,1,1,3,5,5,5,7,9,11,11,11,-1,-1,1};
    //std::vector<int> ev = {0,1,2,3,4,5,6,7,8,9,10};
    Solution sol;
    int n = v.size();
    bool res = false;
    for (int i = 0; i < n; ++i) {
        res = sol.search(v, v[i]);
        assert (res == true);
    }
}

void test9_0() {
    std::vector<int> v = {1,1,1,1,1,3,5,5,5,7,9,11,11,11,-1,-1,1};
    //std::vector<int> ev = {0,1,2,3,4,5,6,7,8,9,10};
    Solution sol;
    int n = v.size();
    bool res = false;
    res = sol.search(v, 0);
    assert (res == false);
}

int main() {
    test0();
    test1();
    test1_0();
    test2();
    test3();
    test3_0();
    test3_1();
    test4();
    test4_0();
    test5();
    test6();
    test6_0();
    test7();
    test8();
    test8_0();
    test9();
    test9_0();
    return 0;
}
