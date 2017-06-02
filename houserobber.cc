#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> loots (nums.size());
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int maxloot = 0;
        loots[0] = nums[0];
        loots[1] = nums[1];
        maxloot = max(loots[0],loots[1]);

        for (int i = 2; i < n; ++i) {
        	loots[i] = nums[i] + max(loots[i - 1], loots[i - 2]);
        	maxloot = max(loots[i - 1], loots[i]);
        }
        return maxloot;
    }
};

void test0() {
	int arr[] = {2,1,1,2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	cout << res << endl;
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