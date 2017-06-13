/*
Leetcode 24. Swap Nodes in Pairs
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
	ListNode* swapPairs(ListNode* head) {
        ListNode *newHead = new ListNode(0);
        ListNode *p = newHead, *q = NULL;
        newHead->next = head;

        while (p->next != NULL) {
        	q = p->next;
        	p->next = q->next;
        	
        	if (p->next != NULL) {
        		q->next = p->next->next;
        		p->next->next = q;
        	}
        	else {
        		p->next = q;
        	}

        	p = q;
        }
        return newHead->next;
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

	ListNode* res = sol.swapPairs(l1);
	std::vector<int> vm = getArrayFromList(res);

	assert (res == NULL && vm.size() == 0);
}

void test1() {
	Solution sol;
	int arr1[] = {1};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	ListNode* res = sol.swapPairs(l1);
	std::vector<int> vm = getArrayFromList(res);

	int arr3[] = {1};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	assert (res != NULL && vm == v3);
}

void test1_1() {
	Solution sol;
	int arr1[] = {9, 10};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	ListNode* res = sol.swapPairs(l1);
	std::vector<int> vm = getArrayFromList(res);

	int arr3[] = {10,9};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	assert (res != NULL && vm == v3);
}

void test2() {
	Solution sol;
	int arr1[] = {3,6,9};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	ListNode* res = sol.swapPairs(l1);
	std::vector<int> vm = getArrayFromList(res);

	int arr3[] = {6,3,9};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	assert (res != NULL && vm == v3);
}

void test3() {
	Solution sol;
	int arr1[] = {1,9,2,8,3,7};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	ListNode* res = sol.swapPairs(l1);
	std::vector<int> vm = getArrayFromList(res);

	int arr3[] = {9,1,8,2,7,3};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	assert (res != NULL && vm == v3);
}

void test4() {
	Solution sol;
	int arr1[] = {1,9,9,8,7,6,4};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	ListNode* res = sol.swapPairs(l1);
	std::vector<int> vm = getArrayFromList(res);

	int arr3[] = {9,1,8,9,6,7,4};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	assert (res != NULL && vm == v3);
}

void test5() {
	Solution sol;
	int arr1[] = {2,4,6,8,10,12,14,16,18,20};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	ListNode* res = sol.swapPairs(l1);
	std::vector<int> vm = getArrayFromList(res);

	int arr3[] = {4,2,8,6,12,10,16,14,20,18};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

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
