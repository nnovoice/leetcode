/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
private:
    int binSearch(vector<int>& nums, int low, int n, int val) {
        int high = n - 1;
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            //cout << mid << " " << nums[mid ] << endl;
            if (nums[mid] == val)
                return mid;
            else if (nums[mid] < val) {
                low = mid + 1;
            }
            else {
                high = mid - 1; 
            }
        }

        return -1;
    }    

public:
    vector<int> twoSumBruteforce(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    ret.push_back(i);
                    ret.push_back(j);
                    return ret;
                }
            }
        }
        return ret;
    }

    vector<int> twoSumUsingBinarySearch(vector<int>& nums, int target) {
        //assert(nums.size() >= 2);
        sort(nums.begin(), nums.end());
        vector<int> r;
        int n = (int) nums.size();
        //cout << n << endl;
        int k = 0, j = 0;
        for (int i = 0; i < n; ++i) {
            k = target - nums[i];
            j = binSearch(nums, i + 1, n, k);
            if (i != j && j != -1) {
                r.push_back(nums[i]);
                r.push_back(nums[j]);
                break;
            }
        }
        return r;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> ret;
        unordered_map<int, int> diffs;
        int d = 0;
        for (int i = 0; i < n; ++i) {
            d = target - nums[i];
            //cout << d << " " << i << " " << endl;
            if (diffs.find(d) != diffs.end()) {
                ret.push_back(diffs[d]);
                ret.push_back(i);
                return ret;
            }
            diffs[nums[i]] = i;
        }
        return ret;
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
    int myints[] = {20, -1, 0, 10, 5, 12, 17, 3, 2, 90};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 17));
    printVector(v1);
    assert(v1[0] == 4 && v1[1] == 5); // these are indicies of the elements
}

void test2() {
    Solution s;
    int myints[] = {20, -1, 1, 10, 5, 12, 17, 3, 2, 90};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 17));
    printVector(v1);
    assert(v1[0] == 4 && v1[1] == 5); // these are indicies of the elements
}

void test3() {
    Solution s;
    int myints[] = {20, -1};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 19));
    printVector(v1);
    assert(v1[0] == 0 && v1[1] == 1);
}

void test4() {
    Solution s;
    int myints[] = {20};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 20));
    printVector(v1);
    assert(v1.size() == 0);
}

void test1Bruteforce() {
    Solution s;
    int myints[] = {20, -1, 1, 10, 5, 12, 17, 3, 2, 90};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSumBruteforce(v, 17));
    printVector(v1);
    assert(v1[0] == 5 && v1[1] == 6); // 1 based index
}

void test2Bruteforce() {
    Solution s;
    int myints[] = {3, 2, 4};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSumBruteforce(v, 6));
    printVector(v1);
    assert(v1[0] == 2 && v1[1] == 3); // 1 based index
}

int main()
{
    test1();
    test2(); 
    test3();   
    test4();
    test1Bruteforce();
    test2Bruteforce();
    return 0;
}
