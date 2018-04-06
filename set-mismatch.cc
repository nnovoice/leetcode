/*
645. Set Mismatch

The set S originally contains numbers from 1 to n. But unfortunately, due to the data error, one of the numbers in the set got duplicated to another number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error. Your task is to firstly find the number occurs twice and then find the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
Note:
The given array size will in the range [2, 10000].
The given array's numbers won't have any order.
*/

#include <vector>
#include <unordered_set>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> numSet;
        vector<int> res;
        for (int n : nums) {
            if (numSet.find(n) != numSet.end()) {
                res.push_back(n);
                if (numSet.find(n-1) != numSet.end())
                    res.push_back(n + 1);
                else
                    res.push_back(n - 1);
                return res;
            }
            numSet.insert(n);
        }
        return res;        
    }
};
void test0() {
    Solution sol;
    vector<int> v = {1,1};
    vector<int> res = sol.findErrorNums(v);
    assert(res[0] == 1 && res[1] == 2);
}

void test1() {
    Solution sol;
    vector<int> v = {2,2};
    vector<int> res = sol.findErrorNums(v);
    assert(res[0] == 2 && res[1] == 1);
}

void test2() {
    Solution sol;
    vector<int> v = {1,2,2};
    vector<int> res = sol.findErrorNums(v);
    assert(res[0] == 2 && res[1] == 3);
}

void test3() {
    Solution sol;
    vector<int> v = {1,2,2,4};
    vector<int> res = sol.findErrorNums(v);
    assert(res[0] == 2 && res[1] == 3);
}

int main() {
    test0();
    test1();
    test2();
    test3();
    //test4();
    return 0;
}