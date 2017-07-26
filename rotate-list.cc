/*
Leetcode: 61. Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
Next:
3Sum Closest
Palindrome Linked List
3Sum Smaller

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

void printList(ListNode *l) {
	ListNode *p = l;
	while (p != nullptr) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << "null" << endl;
}

class Solution {
private:
	int countNodes(ListNode *head) {
		int c = 0;
		for (ListNode *p = head; p != nullptr; p=p->next)
			++c;
		return c;
	}
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k <= 0) return head;
        int n = countNodes(head);
        k = k % n;
        if (k == 0) return head;
        int diff = n - k;
        
        ListNode *pprev = nullptr, *p = head, *q = nullptr, *qtail = nullptr;
        while (p != nullptr && diff != 0) {
        	pprev = p;
        	p = p->next;
        	--diff;
        }
        q = p;
        qtail = q->next;
        while (qtail != nullptr && qtail->next != nullptr)
        	qtail = qtail->next;
        
        if (qtail == nullptr)
        	q->next = head;
        else
        	qtail->next = head;
        
        head = q;
        pprev->next = nullptr;

        return head;
    }
};

void test0() {
	cout << "test0" << endl;
	Solution sol;
	std::vector<int> v1 = {};
	ListNode* l1 = getList(v1);

	ListNode* res = sol.rotateRight(l1,10);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	assert (res == nullptr && vm.size() == 0);
}

void test1() {
	cout << "test1" << endl;
	Solution sol;
	std::vector<int> v1 = {1};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.rotateRight(l1,1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1};
	assert (res != nullptr && vm == v3);
}

void test2() {
	cout << "test2" << endl;
	Solution sol;
	std::vector<int> v1 = {100,1,3};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.rotateRight(l1,2);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,3,100};
	assert (res != nullptr && vm == v3);
}

void test3() {
	cout << "test3" << endl;
	Solution sol;
	std::vector<int> v1 = {1,3,5};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.rotateRight(l1,3);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {1,3,5};
	assert (res != nullptr && vm == v3);
}

void test3_1() {
	cout << "test3_1" << endl;
	Solution sol;
	std::vector<int> v1 = {1,-1,3,-3,5,-5};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.rotateRight(l1,2);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {5,-5,1,-1,3,-3};
	assert (res != nullptr && vm == v3);
}

void test4() {
	cout << "test4" << endl;
	Solution sol;
	std::vector<int> v1 = {12,11,9,-1,0,-10,50,60,9,10};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.rotateRight(l1,5);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {-10,50,60,9,10,12,11,9,-1,0};
	assert (res != nullptr && vm == v3);
}

void test5() {
	cout << "test5" << endl;
	Solution sol;
	std::vector<int> v1 = {12,11,10,10,9,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.rotateRight(l1,18);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {11,10,10,9,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4,12};
	assert (res != nullptr && vm == v3);
}

void test6() {
	cout << "test6" << endl;
	Solution sol;
	std::vector<int> v1 = {-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,9,10,10,11,12};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.rotateRight(l1,5);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {9,10,10,11,12,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9};
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
	test6();
	/*test7();*/
	return 0;
}

