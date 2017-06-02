#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /* there are only 2 cycles to consider in case of even number of elements
           0, 2, 4, 6
           1, 2, 5, 7
           in case of odd number of elements
           0, 2, 4 (6 becomes neighbour of 2)
           1, 3, 5 (7%7 is 0 which is neighbour of 1)
           2, 4, 6 (8%7 is 1 which is the neighbour of 2)
		*/        
        int n = nums.size();
        int cycles = (n % 2 == 0) ? 2 : 3;
        int maxloot = 0, loot = 0;
        for (int i = 0; i < cycles; ++i) {
        	loot = nums[i];
        	int j = (i + 2) % n;
        	while ((j != i) || ((j + 1) != i)) {
        		loot += nums[j];
        		j = (j + 2) % n;
        	}
        	if (maxloot < loot) maxloot = loot; 
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

void test4() {
	int arr[] = {1,3,2};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	Solution sol;
	int res = sol.rob(v);
	assert (res == 3);
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