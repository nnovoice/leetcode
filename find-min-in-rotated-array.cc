/*
Leetcode 153. Find Minimum in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

*/
#include <vector>
#include <stack>
#include <climits>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;


class Solution {
private:
    int getElementUsingBS(vector<int>& nums, int low, int high) {
    if (low > high) return nums[high];
    if (low == high) return nums[low];
    if (high - low == 1) return (nums[low] < nums[high]) ? nums[low] : nums[high];
    
    int mid = 0, ml = 0, mr = 0;
    mid = low + (high - low) / 2;
    ml = mid - 1;
    mr = mid + 1;

    if (nums[ml] > nums[mid] && nums[mid] < nums[mr]) return nums[mid];
    
    int lmin = getElementUsingBS(nums, low, mid - 1);
    int rmin = getElementUsingBS(nums, mid + 1, high);

    return min(lmin, rmin);
}
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return INT_MIN;
        return getElementUsingBS(nums, 0, n - 1);
    }
};

/* Ignore this test
void test0() {
    Solution sol;
    int arr[] = {};
    std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
    int res = sol.findMin(v);
    assert (res == 0);
}*/

void test1() {
    Solution sol;
    int arr[] = {-1};
    std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
    int res = sol.findMin(v);
    assert (res == -1);
}

void test1_1() {
    Solution sol;
    int arr[] = {5};
    std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
    int res = sol.findMin(v);
    assert (res == 5);
}

void test2() {
    Solution sol;
    int arr[] = {1,2,3,4,5};
    std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
    int res = sol.findMin(v);
    assert (res == 1);
}

void test3() {
    Solution sol;
    int arr[] = {1,3,5,7,9,11};
    std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
    int res = sol.findMin(v);
    assert (res == 1);
}

void test4() {
    Solution sol;
    int arr[] = {7,9,11,1,3,5};
    std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
    int res = sol.findMin(v);
    assert (res == 1);
}

void test5() {
    Solution sol;
    int arr[] = {4,6,8,10,0,2};
    std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
    int res = sol.findMin(v);
    assert (res == 0);
}

void test6() {
    Solution sol;
    int arr[] = {10,8,6,4,2,0};
    std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
    int res = sol.findMin(v);
    assert (res == 0);
}

int main() {
    //test0();
    test1();
    test1_1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
