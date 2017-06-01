#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int t = 0;
        // 1, [1, 2, 3, 5, 8, ...]
        int f0 = 1;
        int f1 = 1;
        for (int i = 2; i <= n; ++i) {
        	t = f0;
        	f0 = f1;
        	f1 = f0 + t;
        }
        return f1;
    }
    int climbStairsRecursive (int n) {

    	if (n <= 0) return 0;
    	if (n == 1) return 1;
    	if (n == 2) return 2;
    	return climbStairsRecursive(n - 2) + climbStairsRecursive (n - 1);
    }
};

void test0() {
	Solution sol;
	int res = sol.climbStairs(1);
	assert (res == 1);
}

void test1() {
	Solution sol;
	int res = sol.climbStairs(2);
	assert (res == 2);
}

void test2() {
	Solution sol;
	int res = sol.climbStairs(3);
	assert (res == 3);
}

void test0_recursive() {
	Solution sol;
	int res = sol.climbStairsRecursive(3);
	assert (res == 3);
}

void test1_recursive() {
	Solution sol;
	int res = sol.climbStairsRecursive(10);
	assert (res == 89);
}

int main() {
	test0();
	test1();
	test2();
	test0_recursive();
	test1_recursive();
	return 0;
}