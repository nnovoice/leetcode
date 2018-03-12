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
public:
    vector<int> findShortestSubArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            counts[nums[i]] += 1;
            if (span.find(nums[i]) != span.end())
                span[nums[i]].second = i;
            else
                span.insert(nums[i], make_pair(i, i));
        }

        for (unordered_map<int,int>::iterator iter = counts.begin(); iter != counts.end(); ++iter)
            maxHeap.push(make_pair(iter->first, iter->second));

        pair<int,int> prevElem = make_pair(INT_MIN, INT_MIN);
        pair<int,int> elem = maxHeap.top();
        pair<int,int> curSpan = make_pair(0, INT_MAX), minSpan = span[elem.first];

        for (int i = 0; i < maxHeap.size(); ++i) {
            elem = maxHeap.top();
            if (elem.second < prevElem.second) break;

            curSpan = span[elem.first];

            if ((curSpan.second - curSpan.first) < (minSpan.second - minSpan.first))
                minSpan = curSpan;

            prevElem = elem;
            maxHeap.pop();
        }
        return (minSpan.second - minSpan.first);
    }
};

void printVector(std::vector<int>& v) {
    cout << "printVector\n";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void test0() {
    Solution s;
    std::vector<int> v1 = {1};
    printVector(v1);
    vector<int> topKElements = s.topKFrequent(v1, 1);
    printVector(topKElements);
    assert(topKElements[0] == 1);
}

void test1() {
    Solution s;
    std::vector<int> v1 = {1,2,3,4,5,1,0,0,0,0,0};
    printVector(v1);
    vector<int> topKElements = s.topKFrequent(v1, 2);
    printVector(topKElements);
    assert(topKElements[0] == 0 && topKElements[1] == 1);
}

void test2() {
    Solution s;
    std::vector<int> v1 = {1,3,5,7,9,0,0,0,0,0,9,9,9,1};
    printVector(v1);
    vector<int> topKElements = s.topKFrequent(v1, 3);
    printVector(topKElements);
    assert(topKElements[0] == 0 && topKElements[1] == 9 && topKElements[2] == 1);
}

void test3() {
    Solution s;
    std::vector<int> v1 = {1,1,1,2,2,3};
    printVector(v1);
    vector<int> topKElements = s.topKFrequent(v1, 2);
    printVector(topKElements);
    assert(topKElements[0] == 1 && topKElements[1] == 2);
}

int main()
{
    test0();
    test1();
    test2();
    test3();
    return 0;
}
