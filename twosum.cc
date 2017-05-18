/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
private:
    int binSearch(vector<int>& nums, int low, int high, int val) {
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            //cout << mid << " " << nums[mid ] << endl;
            if (nums[mid] == val)
                return mid;
            else if (nums[mid] < val) {
                low = mid + 1;
            }
            else {
                high = mid - 1; 
            }
        }

        return -1;
    }    

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //assert(nums.size() >= 2);
        sort(nums.begin(), nums.end());
        vector<int> r;
        int n = (int) nums.size();
        //cout << n << endl;
        int k = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            k = target - nums[i];
            j = binSearch(nums, i + 1, n - 1, k);
            if (i != j && j != -1) {
                r.push_back(nums[i]);
                r.push_back(nums[j]);
                break;
            }
        }
        return r;
    }
};

void printVector(std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void test1() {
    Solution s;
    int myints[] = {20, -1, 0, 10, 5, 12, 17, 3, 2, 90};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 17));
    printVector(v1);
    assert(v1[0] == 0 && v1[1] == 17);
}

void test2() {
    Solution s;
    int myints[] = {20, -1, 1, 10, 5, 12, 17, 3, 2, 90};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 17));
    printVector(v1);
    assert(v1[0] == 5 && v1[1] == 12);
}

void test3() {
    Solution s;
    int myints[] = {20, -1};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 19));
    printVector(v1);
    assert(v1[0] == -1 && v1[1] == 20);
}

void test4() {
    Solution s;
    int myints[] = {20};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 20));
    printVector(v1);
    assert(v1[0] == 20 && v1[1] == 20);
}

int main()
{
    test1();
    test2(); 
    test3();   
    test4();
    return 0;
}
