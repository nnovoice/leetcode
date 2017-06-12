/*
Leetcode 2: Add two numbers
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <cstdlib>
#include <vector>
#include <cassert>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *head = new ListNode(0);
        ListNode *p = head;
        int val = 0, carry = 0, x = 0, y = 0;
        while (l1 != NULL || l2 != NULL) {
        	x = (l1 != NULL) ? l1->val : 0;
        	y = (l2 != NULL) ? l2->val : 0;
        	val = x + y + carry;
        	carry = val / 10;
        	p->next = new ListNode(val % 10);
        	l1 = (l1 != NULL) ? l1->next : NULL;
        	l2 = (l2 != NULL) ? l2->next : NULL;
        	p = p->next;
        }
        if (carry != 0) {
        	p->next = new ListNode(carry);
        }
        return head->next;
    }
};

ListNode* getList(std::vector<int>& v) {
	ListNode *head = NULL;
	ListNode *t = NULL;
	if (v.size() == 0) return NULL;
	head = new ListNode(v[0]);
	t = head;
	for (int i = 1; i < v.size(); ++i) {
		t->next = new ListNode(v[i]);
		t = t->next;
	}
	return head;
}

vector<int> getArrayFromList (ListNode* l) {
	std::vector<int> v;
	while (l != NULL) {
		v.push_back(l->val);
		l = l->next;
	}
	return v;
}

void test0() {
	Solution sol;
	int arr1[] = {};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	ListNode* res = sol.addTwoNumbers(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res == NULL && vm.size() == 0);
}

void test1() {
	Solution sol;
	int arr1[] = {1};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {2};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	int arr3[] = {3};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	ListNode* res = sol.addTwoNumbers(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res != NULL && vm == v3);
}

void test1_1() {
	Solution sol;
	int arr1[] = {9};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {2};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	int arr3[] = {1,1};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	ListNode* res = sol.addTwoNumbers(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res != NULL && vm == v3);
}

void test2() {
	Solution sol;
	int arr1[] = {3,6,9};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {1,4,5,9};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	int arr3[] = {4,0,5,0,1};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	ListNode* res = sol.addTwoNumbers(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res != NULL && vm == v3);
}

void test3() {
	Solution sol;
	int arr1[] = {1,9};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {1,9};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	int arr3[] = {2,8,1};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	ListNode* res = sol.addTwoNumbers(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res != NULL && vm == v3);
}

void test4() {
	Solution sol;
	int arr1[] = {1,9,9};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {1,9,9,9};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	int arr3[] = {2,8,9,0,1};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	ListNode* res = sol.addTwoNumbers(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res != NULL && vm == v3);
}

void test5() {
	Solution sol;
	int arr1[] = {2,4,3};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {5,6,4};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	int arr3[] = {7,0,8};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	ListNode* res = sol.addTwoNumbers(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res != NULL && vm == v3);
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
