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

int main() {
	test0();
	test1();
	test2();
	return 0;
}