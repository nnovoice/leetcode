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
using namespace std;

class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> vv;
    unordered_set<int> computed;
    int n = nums.size();
    if (n < 3) return vv;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i + 2 < n; ++i) {
        if (computed.find(nums[i]) != computed.end()) continue;
        computed.insert(nums[i]);
        int t = 0 - nums[i];
    	vector<vector<int>> twoSumPairVectors = twoSum(nums, i + 1, t);
    	if (twoSumPairVectors.size() != 0) {
          	vector<int> tv;
            	
            for (vector<int> twoPairVec : twoSumPairVectors) {
            	tv.push_back(nums[i]);
    			tv.push_back(twoPairVec[0]);
                tv.push_back(twoPairVec[1]);
    			vv.push_back(tv);
                tv = vector<int>();
        	}
        }
    }	  
    return vv;
}
    private:
    vector<vector<int>> twoSum(vector<int>& nums, int start_idx, int target) {
        int n = nums.size();
        vector<std::vector<int>> ret;
        vector<int> v;
        int s = 0;
        int i = start_idx;
        int j = n - 1;
        while (i < j) {
            if (nums[i] > target) break;
            s = nums[i] + nums[j];
            if (s == target) {
                v.push_back(nums[i]);
                v.push_back(nums[j]);
                ret.push_back(v);
                v = vector<int>();
            }
            if (s < target) ++i;
            else --j;
        }
        return ret;
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
    std::vector<int> v = {-20, -1, 0, 10, 5, 12, 17, 3, 2, 90, 20};
    vector<std::vector<int>> v1 (s.threeSum(v));
    printVector(v1);
    //assert(v1[0] == 4 && v1[1] == 5); // these are indicies of the elements
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


    int main()
    {
    test1();
    test2(); 
    test3();   
    test4();
    test5();
    return 0;
    }
