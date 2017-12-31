/*
Leetcode: 217. Contains Duplicate 
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.

*/
#include <vector>
#include <unordered_set>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> eset;
        for (int n : nums) {
            if (eset.find(n) != eset.end()) return true;
            eset.insert(n);
        }
        return false;
    }
};

void test0() {
    Solution s;
    std::vector<int> v = {1,2,3,0};
    bool res = s.containsDuplicate(v);
    assert(res == false);
}

void test1() {
    Solution s;
    std::vector<int> v = {3,2,-1,1,0,1};
    bool res = s.containsDuplicate(v);
    assert(res == true);
}

int main() {
    test0();
    test1();
    /*test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();*/
    return 0;
}