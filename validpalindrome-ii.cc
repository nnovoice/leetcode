/*
Leetcode: 680. Valid Palindrome II 
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

*/
#include <iostream>
#include <cctype>
#include <string>
#include <cassert>
using namespace std;

class Solution {
private:
    bool validPalindrome(string s, int l, int r) {
        char a = ' ', b = ' ';
        int nMismatches = 0;
        bool isValid = true;
        while (l < r) {
            a = s[l];
            b = s[r];
            //cout << s[l] << " " << s[r] << endl;
            if (a != b) {
                ++nMismatches;
                if (s[l+1] == s[r])  {
                    ++l;
                    isValid = validPalindrome(s, l, r);
                    if (isValid == false) --l;
                    else return true;
                }
                if (s[l] == s[r-1]) {
                    --r;
                    isValid = validPalindrome(s, l, r);
                    if (isValid == false) return false;
                }
                else ++nMismatches;
                if (nMismatches > 1) return false;
            }
            else {
                ++l;
                --r;
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        return validPalindrome(s, 0, s.length() - 1);
    }
    
};

void test0() {
	Solution s;
	assert(s.validPalindrome("abb") == true);
}

void test1() {
	Solution s;
	assert(s.validPalindrome("malayalam") == true);
}

void test2() {
	Solution s;
	assert(s.validPalindrome("malayaalam") == true);
}

void test3() {
	Solution s;
	assert(s.validPalindrome("amanaplanacanalpanama") == true);
}

void test4() {
	Solution s;
	assert(s.validPalindrome("raceacar") == true);
}

void test5() {
	Solution s;
	assert(s.validPalindrome("sad") == false);
}

void test6() {
	Solution s;
	assert(s.validPalindrome("akila") == false);
}

void test7() {
    Solution s;
    assert(s.validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga") == true);
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