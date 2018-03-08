/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, e = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[e--] = nums1[i--];
                //e -= 1;
                //i -= 1;
            }
            else {
                nums1[e--] = nums2[j--];
                //e -= 1;
                //j -= 1;
            }
        }

        vector<int>& nums = (i >= 0) ? nums1 : nums2;
        int k = (i >= 0) ? i : j;
        while (k >= 0) {
            nums1[e--] = nums[k--];
        }
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
    std::vector<int> v1 = {1,2,3,4,5,0,0,0,0,0};
    printVector(v1);
    std::vector<int> v2 = {6,7,8,9,10};
    printVector(v2);
    s.merge(v1, 5, v2, 5);
    printVector(v1);
    //assert(v1[0] == 4 && v1[1] == 5); // these are indicies of the elements
}

void test2() {
    Solution s;
    std::vector<int> v1 = {1,3,5,7,9,0,0,0,0,0};
    std::vector<int> v2 = {2,4,6,8,10};
    printVector(v1);
    printVector(v2);
    s.merge(v1, 5, v2, 5);
    printVector(v1);
}

void test3() {
    Solution s;
    std::vector<int> v1 = {1};
    std::vector<int> v2 = {};
    printVector(v1);
    printVector(v2);
    s.merge(v1, 1, v2, 0);
    printVector(v1);
}



int main()
{
    test1();
    test2(); 
    test3();
    return 0;
}
