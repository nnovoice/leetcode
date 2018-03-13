/*
58. Length of Last Word

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        if (n == 0) return 0;
        int len = 0;
        int i = n - 1;
        while (i >= 0 && s[i] == ' ') --i;
        for (; i >= 0 && s[i] != ' '; --i) {
            ++len;
        }
        return len;
    }
};

void test1() {
    Solution s;
    string str = "Hello, World";
    int len = s.lengthOfLastWord(str);
    assert(len == 5);
}

void test2() {
    Solution s;
    string str = "Hello, ";
    int len = s.lengthOfLastWord(str);
    assert(len == 6);
}

void test3() {
    Solution s;
    string str = "";
    int len = s.lengthOfLastWord(str);
    assert(len == 0);
}

void test4() {
    Solution s;
    string str = "Hello,World";
    int len = s.lengthOfLastWord(str);
    assert(len == 11);
}

void test5() {
    Solution s;
    string str = " Hello,";
    int len = s.lengthOfLastWord(str);
    assert(len == 6);
}

void test6() {
    Solution s;
    string str = "a ";
    int len = s.lengthOfLastWord(str);
    assert(len == 1);
}

void test7() {
    Solution s;
    string str = "      ";
    int len = s.lengthOfLastWord(str);
    assert(len == 0);
}

int main()
{
    test1();
    test2(); 
    test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}
