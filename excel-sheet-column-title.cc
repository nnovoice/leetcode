/*
168. Excel Sheet Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB


*/

#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        int digit = 0, num = n;
        string res;
        while (num > 0) {
            digit = num % 26;
            res += (digit == 0) ? 'Z' : ('A' + (digit - 1));
            num /= 26;
            if (digit == 0) num -= 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

void test0() {
	Solution sol;
	string res = sol.convertToTitle(1);
	cout << res << endl;
	assert (res == "A");
}

void test1() {
	Solution sol;
    string res = sol.convertToTitle(26);
    cout << res << endl;
    assert (res == "Z");
}

void test2() {
	Solution sol;
    string res = sol.convertToTitle(27);
    cout << res << endl;
    assert (res == "AA");
}

void test3() {
	Solution sol;
    string res = sol.convertToTitle(52);
    cout << res << endl;
    assert (res == "AZ");
}

void test4() {
	Solution sol;
    string res = sol.convertToTitle(703);
    cout << res << endl;
    assert (res == "AAA");
}

void test5() {
	Solution sol;
    string res = sol.convertToTitle(702);
    cout << res << endl;
    assert (res == "ZZ");
}

void test6() {
	Solution sol;
    string res = sol.convertToTitle(708);
    cout << res << endl;
    assert (res == "AAF");
}

void test7() {
	Solution sol;
    string res = sol.convertToTitle(728);
    cout << res << endl;
    assert (res == "AAZ");
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
	return 0;
}