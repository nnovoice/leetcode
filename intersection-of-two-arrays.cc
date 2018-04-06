/*
350. Intersection of Two Arrays II

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1Map, nums2Map;
        for (int n1 : nums1)
            nums1Map[n1] += 1;

        for (int n2 : nums2)
            nums2Map[n2] += 1;

        vector<int> res;
        int elem = 0, count = 0, diff = 0;
        for (unordered_map<int,int>::iterator mapIter = nums1Map.begin(); mapIter != nums1Map.end(); ++mapIter) {
            elem = mapIter->first;
            if (nums2Map[elem] > 0) {
                count = min(nums1Map[elem], nums2Map[elem]);
                for (int i = 0; i < count; ++i)
                    res.push_back(elem);
            }
        }
        return res;
    }
};

void test0() {
    Solution s;
    std::vector<int> v1 = {};
    std::vector<int> v2 = {};
    vector<int> res = s.intersect(v1, v2);
    assert(res.size() == 0);
}

void test1() {
    Solution s;
    std::vector<int> v1 = {1,2,2,1};
    std::vector<int> v2 = {};
    vector<int> res = s.intersect(v1, v2);
    assert(res.size() == 0);
}

void test2() {
    Solution s;
    std::vector<int> v1 = {1,2,2,1};
    std::vector<int> v2 = {2,2};
    vector<int> res = s.intersect(v1, v2);
    assert(res[0] == 2 && res[1] == 2 && res.size() == 2);
}

int main()
{
    test0();
    test1();
    test2();
    return 0;
}
