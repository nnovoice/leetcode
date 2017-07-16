/*
Leetcode: 237. Delete Node in a Linked List
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

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
    ListNode* deleteNode(ListNode* head, int key) {
    	ListNode* p = NULL, *q =  head;
    	while (q != NULL) {
    		if (q->val == key) {
    			if (p == NULL) {
    				head = head->next;
    			}
    			else {
    				p->next = q->next;
    			}
    			delete q;
    			break;
    		}
    		p = q;
    		q = q->next;	
    	}
    	
    	return head;
    }
    void deleteNode(ListNode* node) {
        ListNode* t = NULL;
        if (node == NULL) return;
        if (node->next != NULL) {
            t = node->next;
            node->val = t->val;
            node->next = t->next;
            delete t;
        }
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

	ListNode* res = sol.deleteNode(l1, 0);
	std::vector<int> vm = getArrayFromList(res);
	assert (res == NULL && vm.size() == 0);
}

void test1() {
	Solution sol;
	std::vector<int> v1 = {1};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteNode(l1, 1);
	std::vector<int> vm = getArrayFromList(res);
	std::vector<int> v3 = {};
	assert (res == NULL && vm == v3);
}

void test2() {
	Solution sol;
	std::vector<int> v1 = {1,3};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteNode(l1, 1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {3};
	assert (res != NULL && vm == v3);
}

void test3() {
	Solution sol;
	std::vector<int> v1 = {1,3,5};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteNode(l1, 5);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,3};
	assert (res != NULL && vm == v3);
}

void test3_1() {
	Solution sol;
	std::vector<int> v1 = {1,3,5};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteNode(l1, 3);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,5};
	assert (res != NULL && vm == v3);
}

void test4() {
	Solution sol;
	std::vector<int> v1 = {1,2,3,5,7,11,13,17};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.deleteNode(l1,7);
	std::vector<int> vm = getArrayFromList(res);
	std::vector<int> v3 = {1,2,3,5,11,13,17};
	assert (res != NULL && vm == v3);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test3_1();
	test4();
/*	test5();
*/	/*test6();
	test7();*/
	return 0;
}

