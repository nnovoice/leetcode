/*
Leetcode: 3. Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
Next challenges: 
Longest substring with at most 2 repeating chars

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
     int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> loc;
        unordered_map<char, int>::iterator iter;
        int mlen = 0, clen = 0;
        char c = ' ';
        for (int i = 0; i < n; ++i) {
            c = s[i];
            if (loc.find(c) == loc.end()) {
                ++clen;
                mlen = max (mlen, clen);
            }
            else {
                int charIndex = loc[c];
                // remove the elements in the map before the char we just found
                int si = charIndex - mlen;
                if (si < 0) si = 0;
                for (int j = si; j < charIndex; ++j) {
                    iter = loc.find(s[j]);
                    if (iter != loc.end())
                        if (iter->second < charIndex)
                            loc.erase(s[j]);
                }
                clen = loc.size();
            }
            // update the char index to i
            loc[c] = i;
        }
        return mlen;        
    }
};

 
void test0() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("");
    assert (res == 0);
}

void test0_1() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("abcabcbb");
    assert (res == 3);
}

void test1() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("bbbbb");
    assert (res == 1);
}

void test1_1() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("pwwkew");
    assert (res == 3);
}

void test2() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("ammapa");
    assert (res == 3);
}

void test3() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("bhagavan");
    assert (res == 4);
}

void test4() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("rendezvous");
    assert (res == 8);
}

void test5() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("triskaidekaphobia");
    assert (res == 9);
}

void test6() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("oompaloompa");
    assert (res == 5);
}

void test7() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("matchpoint");
    assert (res == 9);
}

void test8() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyzabcd");
    assert (res == 26);
}

void test9() {
    Solution sol;
    int res = sol.lengthOfLongestSubstring("the quick brown fox jumped over the lazy dog");
    cout << res;
    assert (res == 11);
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
