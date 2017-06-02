#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int maxEven = 0, maxOdd = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)
                maxEven += nums[i];
            else
                maxOdd += nums[i];
            
        }
        return max(maxEven, maxOdd);
        
    }
};

void test0() {
	int arr[] = {2,1,1,2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 4);
}

void test1() {
	int arr[] = {1,2,3,4,5,6};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 12);
}

void test2() {
	int arr[] = {1,1,2,1,3,1,4,1};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 10);
}

int main() {
	test0();
	test1();
	test2();
	/*test3();
	test4();
	test5();
	test6();*/
	return 0;
}