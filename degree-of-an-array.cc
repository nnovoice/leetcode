/*
697. Degree of an Array

Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

Example 1:
Input: [1, 2, 2, 3, 1]
Output: 2
Explanation:
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.
Example 2:
Input: [1,2,2,3,1,4,2]
Output: 6

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
private:
    struct compare {
      bool operator()(const pair<int,int> l, const pair<int,int> r) {
          return l.second < r.second;
      }
    };

    unordered_map<int,int> counts;
    unordered_map<int,pair<int,int>> span;
    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> maxHeap;

private:
    void updateCounts(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            counts[nums[i]] += 1;
        }
    }
    void updateSpans(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (span.find(nums[i]) != span.end())
                span[nums[i]].second = i;
            else
                span[nums[i]] = make_pair(i, i);
        }
    }
    void createMaxHeap() {
        for (unordered_map<int,int>::iterator iter = counts.begin(); iter != counts.end(); ++iter)
            maxHeap.push(make_pair(iter->first, iter->second));
    }

    int getDegree() {
        pair<int,int> elem = maxHeap.top();
        int maxFreq = elem.second;
        pair<int,int> curSpan = make_pair(0, INT_MAX);
        pair<int,int> minSpan = span[elem.first];

        while (maxHeap.empty() == false) {
            elem = maxHeap.top();

            if (elem.second < maxFreq) {
                break;
            }

            curSpan = span[elem.first];

            if ((curSpan.second - curSpan.first) < (minSpan.second - minSpan.first)) {
                minSpan = curSpan;
            }

            maxHeap.pop();
        }

        // add 1 because indices are stored. Count needs to be derived by adding 1
        return (minSpan.second - minSpan.first + 1);
    }

public:
    int findShortestSubArray(vector<int>& nums) {
        updateCounts(nums);

        updateSpans(nums);

        createMaxHeap();

        return getDegree();
    }
};

void test0() {
    Solution s;
    std::vector<int> v1 = {1};
    
    int degree = s.findShortestSubArray(v1);
    assert(degree == 1);
}

void test1() {
    Solution s;
    std::vector<int> v1 = {1,2,3,4,5,1,0,0,0,0,0};
    
    int degree = s.findShortestSubArray(v1);
    assert(degree == 5);
}

void test2() {
    Solution s;
    std::vector<int> v1 = {9,9,1,3,5,7,9,0,0,0,0,0,9,9,1};
    
    int degree = s.findShortestSubArray(v1);
    assert(degree == 5);
}

void test3() {
    Solution s;
    std::vector<int> v1 = {1,1,1,2,2,3};
    
    int degree = s.findShortestSubArray(v1);
    assert(degree == 3);
}

void test4() {
    Solution s;
    std::vector<int> v1 = {9,9,1,3,5,7,9,0,9,0,0,0,0,9,9,9,1};
    
    int degree = s.findShortestSubArray(v1);
    assert(degree == 16);
}

void test5() {
    Solution s;
    std::vector<int> v1 = {1,2,1,2,1,2,1,2,1,2,1,2};
    
    int degree = s.findShortestSubArray(v1);
    assert(degree == 11);
}

void test6() {
    Solution s;
    std::vector<int> v1 = {1,2,2,3,1,4,2};
    
    int degree = s.findShortestSubArray(v1);
    assert(degree == 6);
}

void test7() {
    Solution s;
    std::vector<int> v1 = {1,2,2,1,2,1,1,1,1,2,2,2};

    int degree = s.findShortestSubArray(v1);
    assert(degree == 9);
}

int main()
{
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}
