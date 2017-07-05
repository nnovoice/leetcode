
/*
387. First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase lettersol.
*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cassert>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int counts [26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            counts[s[i] - 'a'] += 1;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (counts[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};

void test0() {
    string s = "";
    Solution sol;
    int res = sol.firstUniqChar(s);
    assert(res == -1);
}

void test1() {
    string s = "leetcode";
    Solution sol;
    int res = sol.firstUniqChar(s);
    assert(res == 0);
}

void test2() {
    string s = "loveleetcode";
    Solution sol;
    int res = sol.firstUniqChar(s);
    assert(res == 2);
}

void test3() {
    string s = "lolovevelleettccooddee";
    Solution sol;
    int res = sol.firstUniqChar(s);
    assert(res == -1);
}

int main() {
    test0();
    test1();
    test2();
    test3();
    /*test4();
    test5();
    test6();
    test7();
    test8();*/
    return 0;
}