/*
Leetcode: 160. Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
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
private:
	int countNodes(ListNode* l) {
		int count = 0;
		while (l != NULL) {
			++count;
			l = l->next;
		}
		return count;
	}
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL) return NULL;
        if (headB == NULL) return NULL;

        int aCount = countNodes(headA);
        int bCount = countNodes(headB);

        ListNode *l1 = (aCount > bCount) ? headA : headB;
        ListNode *l2 = (aCount > bCount) ? headB : headA;
        
        int diff = (aCount > bCount) ? (aCount - bCount) : (bCount - aCount);
        
        for (int i = 0; i < diff; ++i) {
        	l1 = l1->next;
        }
        
        while (l1 != NULL && l2 != NULL) {
        	if (l1 == l2) 
        		return l1;
        	else {
        		l1 = l1->next;
        		l2 = l2->next;
        	}
        }
        return NULL;
    }
};

void appendNode(ListNode*l, ListNode* node) {
	if (l == NULL) return;
	ListNode *p = l;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = node;
}

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
	std::vector<int> v2 = {};
	ListNode* l1 = getList(v1);
	ListNode* l2 = getList(v2);

	ListNode* res = sol.getIntersectionNode(l1, l2);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	assert (res == NULL && vm.size() == 0);
}

void test1() {
	Solution sol;
	std::vector<int> v1 = {1};
	ListNode* l1 = getList(v1);
	ListNode* l2 = l1;
	ListNode* res = sol.getIntersectionNode(l1, l2);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1};
	assert (res != NULL && vm == v3);
}

void test2() {
	Solution sol;
	std::vector<int> v1 = {3,1};
	ListNode* l1 = getList(v1);

	std::vector<int> v2 = {3,1};
	ListNode* l2 = getList(v2);
	appendNode(l2, l1->next);
	
	ListNode* res = sol.getIntersectionNode(l1, l2);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1};
	assert (res != NULL && vm == v3);
}

void test3() {
	Solution sol;
	std::vector<int> v1 = {100,1000,11,3,5,-1,-100};
	ListNode* l1 = getList(v1);
	std::vector<int> v2 = {3,1};
	ListNode* l2 = getList(v2);
	appendNode(l2, l1->next->next);
	
	ListNode* res = sol.getIntersectionNode(l1, l2);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {11,3,5,-1,-100};
	assert (res != NULL && vm == v3);
}

void test3_1() {
	Solution sol;
	std::vector<int> v1 = {1,3,2,5,0,-1};
	ListNode* l1 = getList(v1);
	std::vector<int> v2 = {3,1};
	ListNode* l2 = getList(v2);
	ListNode* res = sol.getIntersectionNode(l1, l2);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {};
	assert (res == NULL && vm == v3);
}

void test4() {
	Solution sol;
	std::vector<int> v1 = {1,2,3,5,7,11,13,17};
	ListNode* l1 = getList(v1);
	std::vector<int> v2 = {3,1};
	ListNode* l2 = getList(v2);
	appendNode(l2, l1->next->next->next->next->next->next->next);
	ListNode* res = sol.getIntersectionNode(l1, l2);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {17};
	assert (res != NULL && vm == v3);
}

void test5() {
	Solution sol;
	std::vector<int> v1 = {13,11,6,7,5,1,3,2,1,2,3,17,5,7,11,13,17,1};
	ListNode* l1 = getList(v1);
	std::vector<int> v2 = {3,1};
	ListNode* l2 = getList(v2);
	appendNode(l2, l1->next->next->next);
	ListNode* res = sol.getIntersectionNode(l1, l2);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {7,5,1,3,2,1,2,3,17,5,7,11,13,17,1};
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

