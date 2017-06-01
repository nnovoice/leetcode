#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int *p = new int[n+1];
        p[0] = 0;
        p[1] = 1;
        p[2] = 2;
        for (int i = 3; i <= n; ++i) {
            p[i] = p[i-1] + p[i-2];
        }
        int res = p[n];
        delete p;
        return res;
        
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