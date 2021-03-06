/*
Leetcode: 83 remove-duplicates-from-sorted-list
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.


*/
#include <stack>
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head, *temp = nullptr;
        while (p != nullptr) {
            if (p->next != nullptr && p->next->val == p->val) {
                temp = p->next;
                p->next = temp->next;
                delete temp;
            }
            else {
                p = p->next;
            }
        }
        return head;
    }
};

ListNode* getList(std::vector<int>& v) {
	ListNode *head = nullptr;
	ListNode *t = nullptr;
	if (v.size() == 0) return nullptr;
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
	while (l != nullptr) {
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

	ListNode* res = sol.deleteDuplicates(l1);
	std::vector<int> vm = getArrayFromList(res);
	assert (res == nullptr && vm.size() == 0);
}

void test1() {
	Solution sol;
	std::vector<int> v1 = {1,1};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteDuplicates(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1};
	assert (res != nullptr && vm == v3);
}

void test2() {
	Solution sol;
	std::vector<int> v1 = {0,1,1,3,3};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteDuplicates(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {0,1,3};
	assert (res != nullptr && vm == v3);
}

void test3() {
	Solution sol;
	std::vector<int> v1 = {1,1,3,5};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteDuplicates(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,3,5};
	assert (res != nullptr && vm == v3);
}

void test3_1() {
	Solution sol;
	std::vector<int> v1 = {1,3,5};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteDuplicates(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,3,5};
	assert (res != nullptr && vm == v3);
}

void test4() {
	Solution sol;
	std::vector<int> v1 = {1,2,2,3,5,5,7,11,13,17,17};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteDuplicates(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,2,3,5,7,11,13,17};
	assert (res != nullptr && vm == v3);
}

void test5() {
	Solution sol;
	std::vector<int> v1 = {1,1,2,2,3,5,5,7,11,11,13,17,17};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteDuplicates(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,2,3,5,7,11,13,17};
	assert (res != nullptr && vm == v3);
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

