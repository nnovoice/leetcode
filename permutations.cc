    /*
    Leetcode: 46. Permutations

    Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
    */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>
using namespace std;

class Solution {
private:
    void permute(vector<int>& nums, int begin, vector<vector<int>>& result) {
        if (begin >= nums.size()) {
            result.push_back(nums);
        }
        else {
            for (int i = begin; i < nums.size(); ++i) {
                swap(nums[begin], nums[i]);
                permute(nums, begin + 1, result);
                swap(nums[begin], nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std:sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        permute(nums, 0, result);
        return result;
        
    }
};
    void printVector(vector<std::vector<int>>& vv) {
    cout << "printVector\n";
    for (vector<int> v : vv) { 
        for (int a : v) {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << endl;
    }

    void test1() {
    Solution s;
    std::vector<int> v = {1,2,3,0};
    vector<std::vector<int>> v1 (s.permute(v));
    printVector(v1);
    //assert(v1[0] == 4 && v1[1] == 5); // these are indicies of the elements
    }

    void test2() {
    Solution s;
    std::vector<int> v = {3,2,-1,1};
    vector<std::vector<int>> v1 (s.permute(v));
    printVector(v1);
    //assert(v1[0] == 4 && v1[1] == 5);
    }

    void test3() {
    Solution s;
    std::vector<int> v = {0, 1,2,3,5};
    vector<std::vector<int>> v1 (s.permute(v));
    printVector(v1);
    //assert(v1.size() == 0);
    }

    void test4() {
    Solution s;
    std::vector<int> v = {20};
    vector<std::vector<int>> v1 (s.permute(v));
    printVector(v1);
    //assert(v1.size() == 0);
    }

    void test5() {    
    Solution s;
    std::vector<int> v = {-1, 0, 1, 2,-4};
    vector<std::vector<int>> v1 (s.permute(v));
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
    return 0;
    }
