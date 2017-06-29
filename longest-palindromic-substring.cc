/*
Leetcode: 5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

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
private:
    bool checkPalindrome(string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
public:
     string longestPalindrome(string s) {
        int j = s.length() - 1;
        if (j <= 0) return s;
        int i = 0, start = 0, end = j, rs = 0;
        int clen = 0, mlen = 1;
        char c = ' ';

        while (i < j) {
            if (j - i + 1 < mlen) break;
            start = i;
            end = j;
            c = s[start];
            for (; start < end && ((end - start + 1) > mlen); --end) {
                if (s[end] == c) {
                    if (checkPalindrome(s, start, end)) {
                        clen = end - start + 1;
                        if (mlen < clen) {
                            rs = start;
                            mlen = clen;
                        }
                        break;
                    }
                }
            }
            ++i;
        }
        
        return string(s, rs, mlen);        
    }
};

 
void test0() {
    Solution sol;
    string res = sol.longestPalindrome("");
    assert (res == "");
}

void test0_1() {
    Solution sol;
    string res = sol.longestPalindrome("abcabcbb");
    cout << res << endl;
    assert (res == "bcb");
}

void test1() {
    Solution sol;
    string res = sol.longestPalindrome("bbbbb");
    assert (res == "bbbbb");
}

void test1_1() {
    Solution sol;
    string res = sol.longestPalindrome("pwiwkew");
    assert (res == "wiw");
}

void test2() {
    Solution sol;
    string res = sol.longestPalindrome("pammapa");
    assert (res == "pammap");
}

void test3() {
    Solution sol;
    string res = sol.longestPalindrome("bhagavan");
    assert (res == "aga");
}

void test4() {
    Solution sol;
    string res = sol.longestPalindrome("rendezvous");
    assert (res == "r");
}

void test5() {
    Solution sol;
    string res = sol.longestPalindrome("triskaidekaphobia");
    assert (res == "t");
}

void test6() {
    Solution sol;
    string res = sol.longestPalindrome("oompaloompa");
    assert (res == "oo");
}

void test7() {
    Solution sol;
    string res = sol.longestPalindrome("bananabboys");
    assert (res == "bananab");
}

void test8() {
    Solution sol;
    string res = sol.longestPalindrome("boysbanananab");
    assert (res == "banananab");
}

void test9() {
    Solution sol;
    string res = sol.longestPalindrome("panamamanap");
    cout << res;
    assert (res == "panamamanap");
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
