/*
19. Remove Nth Node From End of List
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL || n == 0) return head;
        
        ListNode* p = head, *q = head;
        int count = 0;
        while (q->next != NULL) {
            q = q->next;
            count += 1;
            if (count == n) break;
        }
        while (q->next != NULL) {
            p = p->next;
            q = q->next;
        }
        if (n - count > 1) return head;
        ListNode *temp = NULL;
        if (p == head) {
            temp = p;
            head = head->next;
        }
        else {
            temp = p->next;
            p->next = p->next->next;
        }
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
	std::vector<int> v1 = {};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.removeNthFromEnd(l1,1);
	std::vector<int> vm = getArrayFromList(res);
	assert (res == NULL && vm.size() == 0);
}

void test1() {
	Solution sol;
	std::vector<int> v1 = {1};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.removeNthFromEnd(l1, 1);
	std::vector<int> vm = getArrayFromList(res);
	std::vector<int> v3 = {};
	assert (res != NULL && vm == v3);
}

void test1_1() {
	Solution sol;
	std::vector<int> v1 = {1,2,3,4,5};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.removeNthFromEnd(l1, 1);
	std::vector<int> vm = getArrayFromList(res);
	std::vector<int> v3 = {1,2,3,4};
	assert (res != NULL && vm == v3);
}

void test2() {
	Solution sol;
	std::vector<int> v1 = {1,2};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.removeNthFromEnd(l1, 1);
	std::vector<int> vm = getArrayFromList(res);
	std::vector<int> v3 = {1};
	assert (res != NULL && vm == v3);
}

void test3() {
	Solution sol;
	std::vector<int> v1 = {1,9,2,8,3,7};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.removeNthFromEnd(l1, 6);
	std::vector<int> vm = getArrayFromList(res);
	std::vector<int> v3 = {9,2,8,3,7};
	assert (res != NULL && vm == v3);
}

void test4() {
	Solution sol;
	std::vector<int> v1 = {1,9,2,8,3,7};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.removeNthFromEnd(l1, 5);
	std::vector<int> vm = getArrayFromList(res);
	std::vector<int> v3 = {1,2,8,3,7};
	assert (res != NULL && vm == v3);
}

void test5() {
	Solution sol;
	std::vector<int> v1 = {1,9,2,8,3,7};
	ListNode* l1 = getList(v1);
	ListNode* res = sol.removeNthFromEnd(l1, 4);
	std::vector<int> vm = getArrayFromList(res);
	std::vector<int> v3 = {1,9,8,3,7};
	assert (res != NULL && vm == v3);
}

int main() {
	test0();
	//test1();
	test1_1();
	test2();
	test3();
	test4();
	test5();
	/*test6();
	test7();*/
	return 0;
}
