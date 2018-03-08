/*
414. Third Maximum Number
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
#include <unordered_set>
using namespace std;

class Solution {
private:
    struct compare {
		bool operator() (const int l, const int r) {
			return l < r;
		}
	};
public:
    int thirdMax(vector<int>& nums) {
        unordered_set<int> eset;
        priority_queue<int, vector<int>, compare> maxHeap;
        for (int i = 0; i < nums.size(); ++i) {
            if (eset.find(nums[i]) == eset.end()) {
                maxHeap.push(nums[i]);
                eset.insert(nums[i]);
            }
        }
        if (maxHeap.size() < 3) return maxHeap.top();
        int thirdMax = maxHeap.top();
        for (int i = 0; i < 3 && maxHeap.empty() == false; ++i) {
            thirdMax = maxHeap.top();
            cout << thirdMax << " ";
            maxHeap.pop();
        }
        cout << endl;
        return thirdMax;
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
    int tm = s.thirdMax(v1);
    printVector(v1);
    assert(tm == 3);
}

void test2() {
    Solution s;
    std::vector<int> v1 = {1,3,5,7,9,0,0,0,0,0};
    printVector(v1);
    int tm = s.thirdMax(v1);
    printVector(v1);
    assert(tm == 5);
}

void test3() {
    Solution s;
    std::vector<int> v1 = {1};
    printVector(v1);
    int tm = s.thirdMax(v1);
    printVector(v1);
    assert(tm == 1);
}

void test4() {
    Solution s;
    std::vector<int> v1 = {1,2};
    printVector(v1);
    int tm = s.thirdMax(v1);
    printVector(v1);
    assert(tm == 2);
}

void test5() {
    Solution s;
    std::vector<int> v1 = {1,2,2,3};
    printVector(v1);
    int tm = s.thirdMax(v1);
    printVector(v1);
    assert(tm == 1);
}

int main()
{
    test1();
    test2(); 
    test3();
    test4();
    test5();
    return 0;
}
