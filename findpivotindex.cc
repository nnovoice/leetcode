/*
724. Find Pivot Index My SubmissionsBack to Contest
User Accepted: 612
User Tried: 911
Total Accepted: 923
Total Submissions: 1888
Difficulty: Easy
Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:
Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
Example 2:
Input: 
nums = [1, 2, 3]
Output: -1
Explanation: 
There is no index that satisfies the conditions in the problem statement.
Note:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return 0;
        vector<int> lsums (n, 0);
        vector<int> rsums (n, 0);
        int i = 0, j = n - 1;
        int lsum = 0, rsum = 0;
        while (i < n) {
            lsum += nums[i];
            rsum += nums[j];
            lsums[i] += lsum;
            rsums[j] += rsum;
            ++i;
            --j;
        }
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                if (i + 1 == n) return i;
                if (0 == rsums[i+1]) return i;
            }
            else if (i == n - 1) {
                if (lsums[i - 1] == 0) return i;
                return -1;
            }
            else if (lsums[i - 1] == rsums[i + 1]) return i;
        }
        return -1;
    }
};

int main() {
    return 0;
}