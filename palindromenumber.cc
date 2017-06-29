/*
Leetcode: 9. Palindrome Number

Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Some hints:
Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long int t = x;
        long int y = 0;
        while (t != 0) {
            y = y * 10 + (t % 10);
            t /= 10;
        }
        t = x;
        return (y == t);
    }
};

void test0() {
	Solution sol;
	bool res = sol.isPalindrome(-5);
	assert (res == false);
}

void test1() {
	Solution sol;
	bool res = sol.isPalindrome(0);
	assert (res == true);
}

void test2() {
	Solution sol;
	bool res = sol.isPalindrome(INT_MIN);
	assert (res == false);
}

void test3() {
	Solution sol;
	bool res = sol.isPalindrome(INT_MAX);
	assert (res == false);
}

void test4() {
	Solution sol;
	bool res = sol.isPalindrome(121);
	assert (res == true);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	//test5();
	return 0;
}
