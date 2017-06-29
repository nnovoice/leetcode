/*
Leetcode 66. Plus One
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.


*/

#include <cstdlib>
#include <vector>
#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
    	std::vector<int> res;
    	int n = res.size();
    	if (n == 0) return res;
    	stack<int> st;
    	int c = 1, t = 0;
    	for (int i = n - 1; i >= 0; --i) {

    		t = digits[i] + c;
    		cout << "t=" << t << " c=" << c << endl;
    		st.push(t % 10);
    		c = t / 10;
    	}
    	if (c) st.push(c);
    	while (st.empty() == false) {
    		cout << st.top() << " ";
    		res.push_back(st.top());
    		st.pop();
    	}
    	cout << endl;
    	return res;
    }
};

void test0() {
	Solution sol;
	std::vector<int> v = {1};
	vector<int> vexpected = {2};
	std::vector<int> vm = sol.plusOne(v);
	//assert (vm == vexpected);
}

void test1() {
	Solution sol;
	std::vector<int> v = {1,2,3,4,5};
	vector<int> vexpected = {1,2,3,4,6};
	std::vector<int> vm = sol.plusOne(v);
	assert (vm == vexpected);
}

void test1_1() {
	Solution sol;
	std::vector<int> v = {9};
	vector<int> vexpected = {1,0};
	std::vector<int> vm = sol.plusOne(v);
	assert (vm == vexpected);
}

void test2() {
	Solution sol;
	std::vector<int> v = {9};
	vector<int> vexpected = {1,0};
	std::vector<int> vm = sol.plusOne(v);
	assert (vm == vexpected);
}

void test3() {
	Solution sol;
	std::vector<int> v = {9,9,9,9,9,9};
	vector<int> vexpected = {1,0,0,0,0,0,0};
	std::vector<int> vm = sol.plusOne(v);
	assert (vm == vexpected);
}

void test4() {
	Solution sol;
	std::vector<int> v = {8,9,9,9,9,9,9};
	vector<int> vexpected = {9,0,0,0,0,0,0};
	std::vector<int> vm = sol.plusOne(v);
	assert (vm == vexpected);
}

void test5() {
	Solution sol;
	std::vector<int> v = {8,9,9,9,9,9,8};
	vector<int> vexpected = {8,9,9,9,9,9,9};
	std::vector<int> vm = sol.plusOne(v);
	assert (vm == vexpected);
}

int main() {
	test0();
	test1();
	test1_1();
	test2();
	test3();
	test4();
	test5();
	/*test6();
	test7();*/
	return 0;
}
