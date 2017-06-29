/*
Leetcode: 67. Add Binary
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

*/
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;


class Solution {
public:
     string addBinary(string a, string b) {
        int al = a.length();
        int bl = b.length();
        if (al == 0) return b;
        if (bl == 0) return a;
        stack<char> ans;
        int i = al - 1;
        int j = bl - 1;
        int t = 0, ac = 0, bc = 0, carry = 0;
        while (i >= 0 || j >= 0) {
            ac = (i >= 0) ? a[i] - '0' : 0;
            bc = (j >= 0) ? b[j] - '0' : 0;
            t = ac + bc + carry;
            ans.push('0' + t % 2);
            carry = t / 2;
            --i;
            --j;
        }
        if (carry == 1) ans.push('1');

        string s(ans.size(), '0');
        int k = 0;
        while (ans.empty() == false) {
            s[k++] = ans.top();
            ans.pop();
        }
        return s;
    }
};

 
void test0() {
    Solution sol;
    string res = sol.addBinary("","");
    assert (res == "");
}

void test0_1() {
    Solution sol;
    string res = sol.addBinary("","0");
    assert (res == "0");
}

void test1() {
    Solution sol;
    string res = sol.addBinary("1", "");
    assert (res == "1");
}

void test1_1() {
    Solution sol;
    string res = sol.addBinary("","1");
    assert (res == "1");
}

void test2() {
    Solution sol;
    string res = sol.addBinary("0","0");
    assert (res == "0");
}

void test3() {
    Solution sol;
    string res = sol.addBinary("1","1");
    assert (res == "10");
}

void test4() {
    Solution sol;
    string res = sol.addBinary("11","1");
    assert (res == "100");
}

void test5() {
    Solution sol;
    string res = sol.addBinary("1111","1111");
    assert (res == "11110");
}

void test6() {
    Solution sol;
    string res = sol.addBinary("10000","11111");
    assert (res == "101111");
}

void test7() {
    Solution sol;
    string res = sol.addBinary("000","111");
    assert (res == "111");
}

void test8() {
    Solution sol;
    string res = sol.addBinary("1","1");
    assert (res == "10");
}

void test9() {
    Solution sol;
    string res = sol.addBinary("111111","11111111");
    cout << res;
    assert (res == "100111110");
}

int main() {
    test0();
    test0_1();
    test1();
    test1_1();
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
