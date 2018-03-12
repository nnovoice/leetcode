/*
347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
private:
    struct compare {
      bool operator()(const pair<int,int> l, const pair<int,int> r) {
          return l.second < r.second;
      }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for (int i = 0; i < nums.size(); ++i) {
            counts[nums[i]] += 1;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> maxHeap;
        for (unordered_map<int,int>::iterator iter = counts.begin(); iter != counts.end(); ++iter) {
            maxHeap.push(make_pair(iter->first, iter->second));
        }

        vector<int> topKElements;
        for (int i = 0; i < k; ++i) {
            topKElements.push_back(maxHeap.top().first);
            maxHeap.pop();
        }
        return topKElements;
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
