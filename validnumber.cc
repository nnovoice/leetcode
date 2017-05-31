/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
[spaces][+-][digits][.][digits][e][+-][digits][spaces]
*/

#include <string>
#include <cctype>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
    	bool isNumeric = false;
    	int i = 0, n = s.length();
    	while (i < n && s[i] == ' ') ++i;
    	
    	if (i < n && (s[i] == '+' || s[i] == '-')) ++i;
    	
    	while (i < n && isdigit(s[i])) { 
    		++i;
    		isNumeric = true;
    	}
    	
    	if (i < n && s[i] == '.') ++i;
    	
    	if (i < n && s[i] == 'e') {
    		isNumeric = false;
    		++i;
    		if (i < n && (s[i] == '+' || s[i] == '-')) ++i;
    	}
    	while (i < n && isdigit(s[i])) { 
    		++i;
    		isNumeric = true;
    	}
    	while (i < n && s[i] == ' ') ++i;
    	
    	return isNumeric && (i == n);
    }
    	
};

void test0() {
	string s = "-32768";
	Solution sol;
	bool b = sol.isNumber(s);
	cout << s << " " << b << endl;
	assert(b == true);
}

void test1() {
	string s = "-2147483648";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == true);
}

void test2() {
	string s = "2147483648";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == true);
}
void test3() {
	string s = "-2147483649";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == true);
}
void test4() {
	string s = "           +2147483647";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == true);	
}

void test5() {
	string s = "           +2147483648            ";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == true);
}

void test6() {
	string s = "";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == false);
}

void test7() {
	string s = "+-2";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == false);
}

void test8() {
	string s = "++2";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == false);
}

void test9() {
	string s = " +2 909";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == false);
}

void test10() {
	string s = " 2 909";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == false);
}

void test11() {
	string s = " 2$909";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == false);
}

void test12() {
	string s = "  -0012a42";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == false);	
}

void test13() {
	string s = "  -1e12";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == true);	
}

void test14() {
	string s = "  .e12";
	Solution sol;
	bool b = sol.isNumber(s);
	assert(b == true);	
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
	test8();
	test9();
	test10();
	test11();
	test12();
	test13();
	test14();
	return 0;
}
