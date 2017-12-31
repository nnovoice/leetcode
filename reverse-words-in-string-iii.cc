/*
Leetcode: 557 Reverse Words in a String III
Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.
*/
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, n = s.length();
        while (i < n) {
            while (i < n && s[i] == ' ') ++i;
            j = i;
            while (j < n && s[j] != ' ') ++j;
            --j;
            while (i < j) {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
            while (i < n && s[i] != ' ') ++i;
        }
        return s;
    }
};

int main() {
	Solution sol;
	string res = sol.reverseWords("hello, world");
	assert(res == ",olleh dlrow");	
	return 0;
}
