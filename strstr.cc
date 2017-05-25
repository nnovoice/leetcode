#include <string>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:	
	int strStr(string haystack, string needle) {
		int h = haystack.length();
		int n = needle.length();

		if (n == 0) {
			return 0;
		}

		if (h < n) return -1;

		int i = 0, j = 0;

		while (i < h) {
			if (haystack[i] == needle[j]) {
				int nm = 0;
				for (int k = 0; k < n; ++k) {
					if (haystack[i+k] == needle[j+k]) 
						++nm;
					else 
						break;
				}
				if (nm == n) return i;
			}
			++i;
		}
		return -1;
	}
};

void test0() {
	Solution s;
	string h = "hello, world\n";
	string n = "Hello";
	int index = s.strStr(h, n);
	cout << h << " " << n << " " << index << endl;
	assert(index == -1);
}

void test1() {
	Solution s;
	string h = "Hello, world\n";
	string n = "Hello";
	int index = s.strStr(h, n);
	cout << h << " " << n << " " << index << endl;
	assert(index == 0);
}

void test2() {
	Solution s;
	string h = "";
	string n = "";
	int index = s.strStr(h, n);
	cout << h << " " << n << " " << index << endl;
	assert(index == 0);
}

void test3() {
	Solution s;
	string h = "Ok, hello, world";
	string n = "world";
	int index = s.strStr(h, n);
	cout << h << " " << n << " " << index << endl;
	assert(index == 11);
}

void test4() {
	Solution s;
	string h = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	string n = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int index = s.strStr(h, n);
	cout << h << " " << n << " " << index << endl;
	assert(index == 0);
}

void test5() {
	Solution s;
	string h = "ok";
	string n = "";
	int index = s.strStr(h, n);
	cout << h << " " << n << " " << index << endl;
	assert(index == 0);
}

void test6() {
	Solution s;
	string h = "ok";
	string n = "okok";
	int index = s.strStr(h, n);
	cout << h << " " << n << " " << index << endl;
	assert(index == -1);
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