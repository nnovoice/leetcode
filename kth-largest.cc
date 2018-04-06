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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, compare> maxHeap;
        for (int i = 0; i < nums.size(); ++i) {
            maxHeap.push(nums[i]);
        }

        int kth = maxHeap.top();
        for (int i = 0; i < k; ++i) {
            kth = maxHeap.top();
            //cout << "kth=" << kth << " ";
            maxHeap.pop();
        }
        //cout << "k=" << k << " kth=" << kth << endl;
        return kth;
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
    std::vector<int> v1 = {1,2,3,4,5,0,0,9,10,11};
    printVector(v1);
    int tm = s.findKthLargest(v1, 5);
    printVector(v1);
    assert(tm == 4);
}

void test2() {
    Solution s;
    std::vector<int> v1 = {1,3,5,7,9,0,0,0,0,0};
    printVector(v1);
    int tm = s.findKthLargest(v1, 7);
    printVector(v1);
    assert(tm == 0);
}

void test3() {
    Solution s;
    std::vector<int> v1 = {1};
    printVector(v1);
    int tm = s.findKthLargest(v1, 1);
    printVector(v1);
    assert(tm == 1);
}

void test4() {
    Solution s;
    std::vector<int> v1 = {1,2};
    printVector(v1);
    int tm = s.findKthLargest(v1, 2);
    printVector(v1);
    assert(tm == 1);
}

void test5() {
    Solution s;
    std::vector<int> v1 = {1,2,2,3};
    printVector(v1);
    int tm = s.findKthLargest(v1, 2);
    printVector(v1);
    assert(tm == 2);
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
