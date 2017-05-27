#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include <climits>
using namespace std;

int atoi(string& s) {
	int n = s.length();
	int sign = 1, digit = 0;
	long long num = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == ' ') continue;
		if (s[i] == '+') continue;
		if (s[i] == '-')  { 
			sign = -1; 
			continue; 
		}
		if (isdigit(s[i]) == false) 
			break;
		
		num *= 10;
		digit = s[i] - '0';
		num += digit;
		cout << "num= " << num << " " << digit << endl;
		if (sign == -1) {
			num *= sign;
			sign = 1;
		}
		cout << "num= " << num << endl;
				
		if (num > INT_MAX || num < INT_MIN)
			return 0;			
	}

	return (int) num;
}

void test0() {
	string s = "-32768";
	int a = atoi(s);
	cout << s << " " << a << endl;
	assert(a == -32768);
}

void test1() {
	string s = "-2147483648";
	int a = atoi(s);
	assert(a == -2147483648);
}

void test2() {
	string s = "2147483648";
	int a = atoi(s);
	assert(a == 0);	
}
void test3() {
	string s = "-2147483649";
	int a = atoi(s);
	assert(a == 0);	
}
void test4() {
	string s = "           +2147483647";
	int a = atoi(s);
	assert(a == 2147483647);	
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	return 0;
}