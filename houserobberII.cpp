#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
private:
	int robOriginal(vector<int>& nums, int m, int n) {
        vector<int> loots (nums.size());

        int maxloot = 0;
        int idx1 = 0, idx2 = 0, idx3 = 0;
        int l2 = 0, l3 = 0;
        int m1 = 0, m2 = 0;
        for (int i = m; i <= n; ++i) {
        	idx2 = i - 2;
        	idx3 = i - 3;
        	
        	l2 = (idx2 >= m) ? loots[idx2] : 0;
        	l3 = (idx3 >= m) ? loots[idx3] : 0;
        	
        	loots[i] = nums[i] + max(l2, l3);
        	
        	idx1 = i - 1;

        	m1 = (idx1 >= m) ? loots[idx1] : 0;
        	m2 = loots[i];
        	maxloot = max(m1, m2);
        }
        return maxloot;
    }
public:
    int rob(vector<int>& nums) {
    	if (nums.size() == 0) return 0;
    	if (nums.size() == 1) return nums[0];
        int m1 = robOriginal(nums, 0, nums.size() - 2);
        int m2 = robOriginal(nums, 1, nums.size() - 1);
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

void test3() {
	int arr[] = {1,1,1};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 1);
}

void test3_0() {
	int arr[] = {1,2,3};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 3);
}

void test4() {
	int arr[] = {1,3,2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 3);
}

void test5() {
	int arr[] = {2,7,9,3,1};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 11);
}

void test6() {
	int arr[] = {};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 0);
}

void test7() {
	int arr[] = {2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	cout << "test7" << res << endl;
	assert (res == 2);
}

void test8() {
	int arr[] = {1,3,1,3,100};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 103);	
}

void test9() {
	int arr[] = {1,2,3,4,5,1,2,3,4,5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 16);
}



int main() {
	//test7();
	test0();
	test1();
	test2();
	test3();
	test3_0();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	return 0;
}