/*
Similar to Question [6. Reverse Words in a String], but with the following constraints:
“The input string does not contain leading or trailing spaces and the words are always
separated by a single space.”
Could you do it in-place without allocating extra space?
*/

#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
private:
	void reverseChars(string & s, int start, int end) {
		char c = ' ';
		while (start < end) {
			c = s[start];
			s[start] = s[end];
			s[end] = c;
			++start;
			--end;
		}
	}
public:
    void reverseWords(string &s) {
        reverseChars(s, 0, s.length() - 1);
        int i = 0, j = 0, n = s.length();
        while (j < n) {
        	while (j < n && s[j] != ' ') ++j;
        	reverseChars (s, i, j - 1);
        	++j;
        	i = j;
        }
    }
};

void test0() {
	Solution sol;
	string s = "today's sky is blue and good";
	string t (s);
	sol.reverseWords (s);
	cout << s << endl;
	cout << t << endl;
	assert (s == "good and blue is sky today's");
}

void test1() {
	Solution sol;
	string s = "today's sky is blue and good";

	string t (s);
	sol.reverseWords (s);
	cout << s << endl;
	cout << t << endl;
	assert (s == "good and blue is sky today's");
}

void test2() {
	Solution sol;
	string s = "good";

	string t (s);
	sol.reverseWords (s);
	cout << s << endl;
	cout << t << endl;
	assert (s == "good");
}

void test3() {
	Solution sol;
	string s = "";

	string t (s);
	sol.reverseWords (s);
	cout << s << endl;
	cout << t << endl;
	assert (s == "");
}

void test4() {
	Solution sol;
	string s = " ";

	string t (s);
	sol.reverseWords (s);
	cout << s << s.length() << endl;
	cout << t << t.length() << endl;
	assert (s == " ");
}

void test5() {
	Solution sol;
	string s = "a b";

	string t (s);
	sol.reverseWords (s);
	cout << s << s.length() << endl;
	cout << t << t.length() << endl;
	assert (s == "b a");
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	return 0;
}