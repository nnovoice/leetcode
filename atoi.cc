#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
#include <climits>
using namespace std;




int myAtoi(string s) {
	const long long MAX = (long long) 2147483647;
	const long long MIN = (long long) -2147483648;
	int n = s.length();
	int sign = 1, digit = 0;
	long long num = 0;
	bool plusFound = false, minusFound = false, digitFound = false;
	for (int i = 0; i < n; ++i) {
		if (s[i] == ' ') {
			if (plusFound || minusFound || digitFound) break;
			continue;
		}
		if (s[i] == '+') { 
			if (plusFound) return 0;
			if (minusFound) return 0;
			plusFound = true;
			continue;
		}
		if (s[i] == '-')  {
			if (minusFound) return 0;
			if (plusFound) return 0;
			minusFound = true;
			sign = -1; 
			continue; 
		}
		if (isdigit(s[i]) == false) 
			break;
		
		digitFound = true;
		
		num *= 10;
		digit = s[i] - '0';
		num += digit;
		//cout << "num= " << num << " " << digit << " " << (MAX - num) << endl;
			
		if (sign == 1 && num > MAX) return MAX;
		if (sign == -1 && num > MAX + 1) return MIN; // num remains +ve until later (so compare against 2147483648)
	}

	return (int) (num * sign);
}

void test0() {
	string s = "-32768";
	int a = myAtoi(s);
	cout << s << " " << a << endl;
	assert(a == -32768);
}

void test1() {
	string s = "-2147483648";
	int a = myAtoi(s);
	assert(a == -2147483648);
}

void test2() {
	string s = "2147483648";
	int a = myAtoi(s);
	assert(a == 2147483647);	
}
void test3() {
	string s = "-2147483649";
	int a = myAtoi(s);
	cout << a << endl;
	assert(a == -2147483648);	
}
void test4() {
	string s = "           +2147483647";
	int a = myAtoi(s);
	cout << a << endl;
	assert(a == 2147483647);	
}

void test5() {
	string s = "           +2147483648            ";
	int a = myAtoi(s);
	cout << a << endl;
	assert(a == 2147483647);	
}

void test6() {
	string s = "";
	int a = myAtoi(s);
	cout << a << endl;
	assert(a == 0);	
}

void test7() {
	string s = "+-2";
	int a = myAtoi(s);
	cout << a << endl;
	assert(a == 0);	
}

void test8() {
	string s = "++2";
	int a = myAtoi(s);
	cout << a << endl;
	assert(a == 0);	
}

void test9() {
	string s = " +2 909";
	int a = myAtoi(s);
	cout << a << endl;
	assert(a == 2);	
}

void test10() {
	string s = " 2 909";
	int a = myAtoi(s);
	cout << a << endl;
	assert(a == 2);	
}

void test11() {
	string s = " 2$909";
	int a = myAtoi(s);
	cout << a << endl;
	assert(a == 2);	
}

void test12() {
	string s = "  -0012a42";
	int a = myAtoi(s);
	cout << a << endl;
	assert(a == -12);	
}

void findOverflow() {
	int m = 214748364;
	int n = 0;
	bool quit = false;
	for (int k = m; k < 214748366; ++k) {
		cout << k << endl;
		for (int i = 1; i < 10; ++i) {
			n = k * i;
			if ( n < 0) { quit = true; break; }
			cout << i << "\t" << "\t" << INT_MAX << "\t" << n << "\t" << (INT_MAX - n) << endl;
		}
		if (quit) break;
		cout << endl;
	}
}

int main() {
	//findOverflow();
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
	return 0;
}