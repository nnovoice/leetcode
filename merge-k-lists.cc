#include <queue>
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
	struct compare {
		bool operator() (const ListNode* l, const ListNode* r) {
			return l->val > r->val;
		}
	};

    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, compare > pq;
		for (auto l : lists) {
			if (l) pq.push(l);
		}
		ListNode *head = new ListNode(0);
		ListNode *p = head, *q = NULL;

		while (pq.empty() == false) {
			q = pq.top();
			pq.pop();
			if (q->next) pq.push(q->next);
			p->next = q;
			p = p->next;
		}
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

void test0() {
	Solution sol;
	int arr1[] = {};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	std::vector<ListNode*> vl;
	vl.push_back(l1);
	vl.push_back(l2);

	ListNode* res = sol.mergeKLists(vl);
	std::vector<int> vm = getArrayFromList(res);

	assert (res == NULL && vm.size() == 0);
}

void test1() {
	Solution sol;
	int arr1[] = {1};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	std::vector<ListNode*> vl;
	vl.push_back(l1);
	vl.push_back(l2);

	ListNode* res = sol.mergeKLists(vl);
	std::vector<int> vm = getArrayFromList(res);

	int arr3[] = {1};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	assert (res != NULL && vm == v3);
}

void test2() {
	Solution sol;
	int arr1[] = {1,3,5};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {2,4,6};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	std::vector<ListNode*> vl;
	vl.push_back(l1);
	vl.push_back(l2);

	ListNode* res = sol.mergeKLists(vl);
	std::vector<int> vm = getArrayFromList(res);

	int arr3[] = {1,2,3,4,5,6};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));

	assert (res != NULL && vm == v3);
}

void test3() {
	Solution sol;
	int arr1[] = {1,3,5,7,11,13,17};
	std::vector<int> v1 (arr1, arr1 + (sizeof(arr1)/sizeof(int)));
	ListNode* l1 = getList(v1);

	int arr2[] = {2,4,6,10,13,16,20};
	std::vector<int> v2 (arr2, arr2 + (sizeof(arr2)/sizeof(int)));
	ListNode* l2 = getList(v2);

	int arr3[] = {19,99,100,101};
	std::vector<int> v3 (arr3, arr3 + (sizeof(arr3)/sizeof(int)));
	ListNode* l3 = getList(v3);

	std::vector<ListNode*> vl;
	vl.push_back(l1);
	vl.push_back(l2);
	vl.push_back(l3);

	ListNode* res = sol.mergeKLists(vl);
	std::vector<int> vm = getArrayFromList(res);

	int arr[] = {1,2,3,4,5,6,7,10,11,13,13,16,17,19,20,99,100,101};
	std::vector<int> vr (arr, arr + (sizeof(arr)/sizeof(int)));

	assert (res != NULL && vm == vr);
}

int main() {
	test0();
	test1();
	test2();
	test3();
/*	test4();
	test5();
*/	/*test6();
	test7();*/
	return 0;
}

