    /*
    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

    Note: The solution set must not contain duplicate triplets.

    For example, given array S = [-1, 0, 1, 2, -1, -4],

    A solution set is:
    [
    [-1, 0, 1],
    [-1, -1, 2]
    ]
    */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, minDiff = INT_MAX;
        int sum = 0, minSum = INT_MAX;
        for (int i = 0; i+2 < nums.size(); ++i) {
            sum = nums[i] +  nums[i+1] + nums[i+2];
            if (sum == target) return sum;
            if (sum < target) {
                diff = target - sum;
                minDiff = diff;
                minSum = sum;
            }
            else {
                diff = target + sum;
                break;
            }            
        }
        if (diff < minDiff) return sum;
        return minSum;
    }
};

void printVector(vector<std::vector<int>>& vv) {
    cout << "printVector\n";
    for (int a : v) {
       cout << a << " ";
    }
    cout << endl;
}

    void test1() {
    Solution s;
    std::vector<int> v = {-20, -1, 0, 10, 5, 12, 17, 3, 2, 90, 20};
    vector<std::vector<int>> v1 (s.threeSum(v));
    printVector(v1);
    //assert(v1[0] == 4 && v1[1] == 5); // these are indices of the elements
    }

    void test2() {
    Solution s;
    std::vector<int> v = {20, -19, -1, -10, -5, 15, 12, 17, 3, 2, 90};
    vector<std::vector<int>> v1 (s.threeSum(v));
    printVector(v1);
    //assert(v1[0] == 4 && v1[1] == 5);
    }

    void test3() {
    Solution s;
    std::vector<int> v = {0, 0, 0, 0};
    vector<std::vector<int>> v1 (s.threeSum(v));
    printVector(v1);
    //assert(v1.size() == 0);
    }

    void test4() {
    Solution s;
    std::vector<int> v = {20};
    vector<std::vector<int>> v1 (s.threeSum(v));
    printVector(v1);
    assert(v1.size() == 0);
    }

    void test5() {    
    Solution s;
    std::vector<int> v = {-1, 0, 1, 2, -1, -4};
    vector<std::vector<int>> v1 (s.threeSum(v));
    printVector(v1);
    //assert(v1.size() == 0);
    }


    void test6() {    
    Solution s;
    std::vector<int> v = {-1, 0, -1, 1, 1, 1, 2, -1, -4};
    vector<std::vector<int>> v1 (s.threeSum(v));
    printVector(v1);
    //assert(v1.size() == 0);
    }

    int main()
    {
    test1();
    test2(); 
    test3();   
    test4();
    test5();
    test6();
    return 0;
    }
