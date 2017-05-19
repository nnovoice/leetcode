/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution and you may not use the same element twice.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Input: numbers = {-1, 0, 2, 3, 5, 10, 12, 17, 20, 90}; target = 90
Output: index1=2, index2=10

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
        int low = 0, high = n - 1, s = 0;
        while (low < high) {
            s = nums[low] + nums[high];
            if (s == target) {
                ret.push_back(low + 1); // 1-based index
                ret.push_back(high + 1);// 1-based index
                return ret;
            }
            if (s > target) --high;
            else ++low;
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
    int myints[] = {-1, 0, 2, 3, 5, 10, 12, 17, 20, 90};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 17));
    printVector(v1);
    assert(v1[0] == 2 && v1[1] == 8); // these are indicies of the elements
    assert(v1[0] < v1[1]);
}

void test2() {
    Solution s;
    int myints[] = {-1, 0, 2, 3, 5, 10, 12, 17, 20, 90};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 22));
    printVector(v1);
    assert(v1[0] == 3 && v1[1] == 9); // these are indicies of the elements
    assert(v1[0] < v1[1]);
}

void test3() {
    Solution s;
    int myints[] = {-1, 20};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 19));
    printVector(v1);
    assert(v1[0] == 1 && v1[1] == 2);
    assert(v1[0] < v1[1]);
}

void test4() {
    Solution s;
    int myints[] = {20};
    std::vector<int> v (myints, myints + sizeof(myints) / sizeof(int) );
    std::vector<int> v1 (s.twoSum(v, 20));
    printVector(v1);
    assert(v1.size() == 0);
}

int main()
{
    test1();
    test2(); 
    test3();   
    test4();
    return 0;
}
