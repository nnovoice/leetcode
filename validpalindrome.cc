#include <iostream>
#include <cctype>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        char a = ' ', b = ' ';
        int l = 0, r = s.length() - 1;
        //cout << l << " " << r << endl;
        while (l <  r) {
        	while (l < r && isalnum(s[l]) == false) ++l;
        	while (l < r && isalnum(s[r]) == false) --r;

        	//if (l > r) return false;

        	a = tolower(s[l]); // tolower of a non alphanumeric char does not change it.
        	b = tolower(s[r]);

        	//cout << a << " " << b << endl;

        	if (a != b) return false;

        	++l;
        	--r;
        }
        return true;
    }
};

void test0() {
	Solution s;
	assert(s.isPalindrome("") == true);
}

void test1() {
	Solution s;
	assert(s.isPalindrome("malayalam") == true);
}

void test2() {
	Solution s;
	assert(s.isPalindrome("malayaalam") == false);
}

void test3() {
	Solution s;
	assert(s.isPalindrome("A man, a plan, a canal: Panama") == true);
}

void test4() {
	Solution s;
	assert(s.isPalindrome("race a car") == false);
}

void test5() {
	Solution s;
	assert(s.isPalindrome(" ") == true);
}

void test6() {
	Solution s;
	assert(s.isPalindrome("     ") == true);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}