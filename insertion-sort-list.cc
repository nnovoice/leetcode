/*
Leetcode: 147. Insertion Sort List
Sort a linked list using insertion sort.
*/
#include <stack>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *p = head, *ptemp = NULL;
        ListNode *sHead = NULL, *s = NULL, *sPrev = NULL;
        while (p != NULL) {
        	s = sHead;
        	sPrev = NULL;
        	while (s != NULL && s->val <= p->val) {
        		sPrev = s;
        		s = s->next;
        	}
        	ptemp = p;
        	p = p->next;
        	if (sPrev == NULL) {
        		if (sHead != NULL) {
        			ptemp->next = sHead;
        			sHead = ptemp;
        		}
        		else {
	        		sPrev = ptemp;
	        		sPrev->next = NULL;
	        		sHead = sPrev;
        		}
        	}
        	else {
        		ptemp->next = sPrev->next;
        		sPrev->next = ptemp;
        	}
        }
        return sHead;
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

void printArray(vector<int>& v) {
	for (auto a : v)
		cout << a << " ";
	cout << endl;
}

void test0() {
	Solution sol;
	std::vector<int> v1 = {};
	ListNode* l1 = getList(v1);

	ListNode* res = sol.insertionSortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	assert (res == NULL && vm.size() == 0);
}

void test1() {
	Solution sol;
	std::vector<int> v1 = {1};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.insertionSortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1};
	assert (res != NULL && vm == v3);
}

void test2() {
	Solution sol;
	std::vector<int> v1 = {3,1};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.insertionSortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,3};
	assert (res != NULL && vm == v3);
}

void test3() {
	Solution sol;
	std::vector<int> v1 = {100,1000,11,3,5,-1,-100};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.insertionSortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {-100,-1,3,5,11,100,1000};
	assert (res != NULL && vm == v3);
}

void test3_1() {
	Solution sol;
	std::vector<int> v1 = {1,3,2,5,0,-1};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.insertionSortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {-1,0,1,2,3,5};
	assert (res != NULL && vm == v3);
}

void test4() {
	Solution sol;
	std::vector<int> v1 = {1,2,3,5,7,11,13,17};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.insertionSortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,2,3,5,7,11,13,17};
	assert (res != NULL && vm == v3);
}

void test5() {
	Solution sol;
	std::vector<int> v1 = {13,11,6,7,5,1,3,2,1,2,3,17,5,7,11,13,17,1};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.insertionSortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,1,1,2,2,3,3,5,5,6,7,7,11,11,13,13,17,17};
	assert (res != NULL && vm == v3);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test3_1();
	test4();
	test5();
	/*test6();
	test7();*/
	return 0;
}

