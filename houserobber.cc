#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> loots (nums.size());

        int n = nums.size();
        int maxloot = 0;
        int idx1 = 0, idx2 = 0, idx3 = 0;
        int l2 = 0, l3 = 0;
        int m1 = 0, m2 = 0;
        for (int i = 0; i < n; ++i) {
        	idx2 = i - 2;
        	idx3 = i - 3;
        	
        	l2 = (idx2 >= 0) ? loots[idx2] : 0;
        	l3 = (idx3 >= 0) ? loots[idx3] : 0;
        	
        	loots[i] = nums[i] + max(l2, l3);
        	
        	idx1 = i - 1;

        	m1 = (idx1 >= 0) ? loots[idx1] : 0;
        	m2 = loots[i];
        	maxloot = max(m1, m2);
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