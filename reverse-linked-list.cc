/*
Leetcode: 206. Reverse Linked List

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
    ListNode* reverseList(ListNode* head) {
    	stack<ListNode*> st;
    	ListNode* p = head;
    	while (p != NULL) {
    		st.push(p);
    		p = p->next;
    	}
    	p = new ListNode(0);
    	head = p;
    	while (st.empty() == false) {
    		p->next = st.top();
    		cout << p->next->val << " ";
    		st.pop();
    	}
    	cout << endl;
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

void printArray(vector<int>& v) {
	for (auto a : v)
		cout << a << " ";
	cout << endl;
}

void test0() {
	Solution sol;
	std::vector<int> v1 = {};
	ListNode* l1 = getList(v1);

	ListNode* res = sol.reverseList(l1);
	std::vector<int> vm = getArrayFromList(res);
	assert (res == NULL && vm.size() == 0);
}

void test1() {
	Solution sol;
	std::vector<int> v1 = {1};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.reverseList(l1);
	std::vector<int> vm = getArrayFromList(res);
	std::vector<int> v3 = {1};
	assert (res != NULL && vm == v3);
}

void test2() {
	Solution sol;
	std::vector<int> v1 = {1,3};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.reverseList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {3,1};
	assert (res != NULL && vm == v3);
}

void test3() {
	Solution sol;
	std::vector<int> v1 = {1,3,5};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.reverseList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {5,3,1};
	assert (res != NULL && vm == v3);
}

void test4() {
	Solution sol;
	std::vector<int> v1 = {1,3,5,7,11,13,17};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.reverseList(l1);
	std::vector<int> vm = getArrayFromList(res);
	std::vector<int> v3 = {17,13,11,7,5,3,2,1};
	assert (res != NULL && vm == v3);
}

int main() {
	test0();
	test1();
	//test2();
	test3();
	test4();
/*	test5();
*/	/*test6();
	test7();*/
	return 0;
}

