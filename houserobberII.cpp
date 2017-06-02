#include <vector>
#include <stack>
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
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int cycles = (n % 2 == 0) ? 2 : 3;
        int maxloot = 0, loot = 0;
        stack<int> left;
        stack<int> right;
        int l = 0, r = 0;
        for (int i = 0; i < cycles; ++i) {
        	// need to do this to wrap the -ve index back to +ve
        	l = (n + (i - 2) % n) % n; 
        	r = (i + 2) % n;
        	while (1) {
        		if (cycles == 3 && (((r + 1) % n) == i)) break;
        		if (cycles == 2 && r == i) break;
        		cout << "cycles=" << cycles << " n=" << n << " i=" << i << " l=" << l << " r=" << r << endl;
        		left.push(l);
        		right.push(r);
        		l = (n + (l - 2) % n) % n;
        		r = (r + 2) % n;
        	}
        	int lloot = nums[i], rloot = nums[i];
        	while (left.empty() == false) {
        		lloot += nums[left.top()];
        		rloot += nums[right.top()];
        		left.pop();
        		right.pop();
        	}
        	maxloot = max(maxloot, max(lloot, rloot));
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
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	return 0;
}