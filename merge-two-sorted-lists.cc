/*
Leetcode 21
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


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
    ListNode* mergeTwoLists(ListNode* la, ListNode* lb) {
        if (la == NULL) return lb;
        if (lb == NULL) return la;
        ListNode *head = NULL, *p1 = NULL, *l1 = NULL, *l2 = NULL;
        l1 = (la->val <= lb->val) ? la : lb;
        l2 = (la->val <= lb->val) ? lb : la;
        head = l1;
        while (l1 != NULL && l2 != NULL) {
        	if (l1->val <= l2->val) {
        		p1 = l1;
        		l1 = l1->next;
        	}
        	else {
        		p1->next = l2;
        		l2 = l2->next;
        		p1 = p1->next;
        		p1->next = l1;
        	}
        }
        if (p1 != NULL && l2 != NULL)
        	p1->next = l2;
        return head;
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

	ListNode* res = sol.mergeTwoLists(l1, l2);
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

	int arr3[] = {1, 2};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	ListNode* res = sol.mergeTwoLists(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res != NULL && vm == v3);
}

void test1_1() {
	Solution sol;
	int arr1[] = {1};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {1};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	int arr3[] = {1, 1};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	ListNode* res = sol.mergeTwoLists(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res != NULL && vm == v3);
}

void test2() {
	Solution sol;
	int arr1[] = {3,6,9};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {1,4,5,10};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	int arr3[] = {1,3,4,5,6,9,10};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	ListNode* res = sol.mergeTwoLists(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res != NULL && vm == v3);
}

void test3() {
	Solution sol;
	int arr1[] = {1,2,3,6,9,100};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {10,11,201};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	int arr3[] = {1,2,3,6,9,10,11,100,201};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	ListNode* res = sol.mergeTwoLists(l1, l2);
	std::vector<int> vm = getArrayFromList(res);

	assert (res != NULL && vm == v3);
}

int main() {
	test0();
	test1();
	test1_1();
	test2();
	test3();
	/*test4();
	test5();*/
	/*test6();
	test7();*/
	return 0;
}
