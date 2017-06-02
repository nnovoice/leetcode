#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> loots (nums.size());

        int n = nums.size();
        int m1 = 0, m2 = 0;
        for (int i = 0; i < n; ++i) {
        	if (i % 2 == 0) m2 += nums[i];
        	else m1 += nums[i];
        }
        return max(m1, m2);
    }
};

void test0() {
	int arr[] = {2,1,1,2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	cout << res << endl;
	assert (res == 3);
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