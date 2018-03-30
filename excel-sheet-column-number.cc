/*
171. Excel Sheet Column Number
Related to question Excel Sheet Column Title

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28

*/

#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length() - 1;
        int num = 0, placeVal = 1;
        for (int i = n; i >= 0; --i) {
            placeVal = 1;
            for (int j = 0; j < n - i; ++j)
                placeVal *= 26;
            placeVal *= (s[i] - 'A' + 1);
            num += placeVal;
        }
        return num;
    }
};

void test0() {
	Solution sol;
	int res = sol.titleToNumber("A");
	assert (res == 1);
}

void test1() {
	Solution sol;
    int res = sol.titleToNumber("Z");
    assert (res == 26);
}

void test2() {
	Solution sol;
    int res = sol.titleToNumber("AA");
    assert (res == 27);
}

void test3() {
	Solution sol;
    int res = sol.titleToNumber("AZ");
    assert (res == 52);
}

void test4() {
	Solution sol;
    int res = sol.titleToNumber("AAA");
    assert (res == 703);
}

void test5() {
	Solution sol;
    int res = sol.titleToNumber("ZZ");
    assert (res == 702);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}