/*
Leetcode: 219. Contains Duplicate II 
Given an array of integers and an integer k, find out whether there are 
two distinct indices i and j in the array such that nums[i] = nums[j] 
and the absolute difference between i and j is at most k.
*/
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> eset;
        unordered_map<int, vector<int>> places;
        
        for (int i = 0; i < nums.size(); ++i) {
            eset.insert(nums[i]);
            places[nums[i]].push_back(i);
        }
        
        auto iter = eset.begin();
        for (; iter != eset.end(); ++iter) {
            vector<int>& v = places[*iter];
            int n = v.size();
            if (n > 0) {
                for (int i = 0; i < n - 1; ++i) {
                    if (v[i+1] - v[i] <= k) return true;
                }
            }
        }
        
        return false;
    }
};

void test0() {
    Solution s;
    std::vector<int> v = {1,2,3,0};
    bool res = s.containsNearbyDuplicate(v, 1);
    assert(res == false);
}

void test1() {
    Solution s;
    std::vector<int> v = {3,2,-1,1,0,1};
    bool res = s.containsNearbyDuplicate(v, 1);
    assert(res == false);
}

void test2() {
    Solution s;
    std::vector<int> v = {3,2,-1,1,0,1};
    bool res = s.containsNearbyDuplicate(v, 2);
    assert(res == true);
}

void test3() {
    Solution s;
    std::vector<int> v = {3,2,-1,1,0,1};
    bool res = s.containsNearbyDuplicate(v, 3);
    assert(res == true);
}

void test4() {
    Solution s;
    std::vector<int> v = {3,2,-1,1,0,1};
    bool res = s.containsNearbyDuplicate(v, 1);
    assert(res == false);
}

int main() {
    test0();
    test1();
    test2();
    test3();
    test4();
    /*test5();
    test6();
    test7();
    test8();*/
    return 0;
}