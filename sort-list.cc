/*
Leetcode: 148. Sort List
Sort a linked list in O(n log n) time using constant space complexity.
Next: sort colors
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
		ListNode *p = head;
		int c = 0;
		while (p != nullptr) {
			++c;
			p = p->next;
		}
		//cout << "count=" << c << endl;
		return c;
	}
	void splitList(ListNode *head, pair<ListNode*, ListNode*>& nodePair, int count) {
		if (head == nullptr || count == 0) return;
		ListNode *p = head, *prev = nullptr;
		while (p != nullptr && count != 0) {
			prev = p;
			p = p->next;
			--count;
		}
		prev->next = nullptr;
		nodePair.first = head;
		nodePair.second = p;
		//printList(nodePair.first);
		//printList(nodePair.second);
	}
	ListNode* mergeLists(ListNode *l, ListNode *r) {
		if (l == nullptr) return r;
		if (r == nullptr) return l;
		
		ListNode *p = (l->val <= r->val) ? l : r;
		ListNode *q = (l->val <= r->val) ? r : l;
		ListNode *tq = nullptr, *pprev = nullptr;
		ListNode *merged = p;;
		
		while (p != nullptr && q != nullptr) {
			if (p->val <= q->val) {
				pprev = p;
				p = p->next;
			}
			else {
				tq = q->next;
				q->next = p;
				if (p == merged) {
					merged = q;
				}
				pprev->next = q;
				pprev = q;
				q = tq;
			}
		}
		if (q != nullptr) {
			pprev->next = q;
		}
		return merged;
	}
public:
    ListNode* sortList(ListNode* head) {
        int count = countNodes(head);
        if (count <= 1) return head;
        pair<ListNode*, ListNode*> nodePair;
        ListNode *p = nullptr, *q = nullptr;
        splitList(head, nodePair, count/2);
        //printList(nodePair.first);
        //printList(nodePair.second);
        p = sortList(nodePair.first);
        q = sortList(nodePair.second);
        ListNode *s = mergeLists(p, q);
        //printList(s);
        return s;
    }
};


void test0() {
	Solution sol;
	std::vector<int> v1 = {};
	ListNode* l1 = getList(v1);

	ListNode* res = sol.sortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	assert (res == nullptr && vm.size() == 0);
}

void test1() {
	Solution sol;
	std::vector<int> v1 = {1};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.sortList(l1);
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
	ListNode* res = sol.sortList(l1);
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
	ListNode* res = sol.sortList(l1);
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
	ListNode* res = sol.sortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {-5,-3,-1,1,3,5};
	assert (res != nullptr && vm == v3);
}

void test4() {
	cout << "test4" << endl;
	Solution sol;
	std::vector<int> v1 = {12,11,9,-1,0,-10,50,60,9,10};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.sortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {-10,-1,0,9,9,10,11,12,50,60};
	assert (res != nullptr && vm == v3);
}

void test5() {
	cout << "test5" << endl;
	Solution sol;
	std::vector<int> v1 = {12,11,10,10,9,9,8,7,6,5,4,3,2,1,0,-1,-2,-3,-4};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.sortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,9,10,10,11,12};
	assert (res != nullptr && vm == v3);
}

void test6() {
	cout << "test6" << endl;
	Solution sol;
	std::vector<int> v1 = {-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,9,10,10,11,12};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.sortList(l1);
	std::vector<int> vm = getArrayFromList(res);
	printArray(vm);
	std::vector<int> v3 = {-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,9,10,10,11,12};
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

