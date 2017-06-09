/*
Leetcode: 109
Given a singly linked list where elements are sorted in ascending order, 
convert it to a height balanced BST.
*/
#include <vector>
#include <stack>
#include <climits>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for a binary tree node.
*/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
	ListNode* p;

	TreeNode* sortedListToBST(int low, int high) {
    	if (low > high) return NULL;
        int median = low + (high - low) / 2;
        
        TreeNode* left = sortedListToBST(low, median - 1);
        TreeNode* parent = new TreeNode(p->val);
        p = p->next;
        TreeNode* right = sortedListToBST(median + 1, high);
        parent->left = left;
        parent->right = right;

        return parent;
    }    
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	if (head == NULL) return NULL;
    	int n = 0;
    	ListNode* t = head;
    	while (t) {
    		++n;
    		t = t->next;
    	}
    	
    	p = head;
    	// convert n to an index like in an array {n is the count right now}
    	return sortedListToBST(0, n - 1);
    }
};

void inorderTraverse(TreeNode* root, std::vector<int>& v) {
	if (root == NULL) return;
	inorderTraverse(root->left, v);
	v.push_back(root->val);
	inorderTraverse(root->right, v);
}

vector<int> getSortedArray(TreeNode* root) {
	std::vector<int> v;
	inorderTraverse(root, v);
	return v;
}

ListNode* getList(std::vector<int>& v) {
	ListNode *head = NULL;
	ListNode *t = NULL;
	if (v.size() == 0) return NULL;
	head = new ListNode(v[0]);
	//cout << head->val << " ";
	t = head;
	//cout << " " << t->val;
	for (int i = 1; i < v.size(); ++i) {
		t->next = new ListNode(v[i]);
		//cout << " " << t->val;
		t = t->next;
	}
	return head;
}

void printList(ListNode* l) {
	while (l) {
		cout << l->val << " ";
		l = l->next;
	}
}

void test0() {
	Solution sol;
	int arr[] = {};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	ListNode* l = getList(v);
	TreeNode* res = sol.sortedListToBST(l);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

void test1() {
	Solution sol;
	int arr[] = {1};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	ListNode* l = getList(v);
	TreeNode* res = sol.sortedListToBST(l);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

void test2() {
	Solution sol;
	int arr[] = {1,2,3,4};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	ListNode* l = getList(v);
	//printList(l);
	TreeNode* res = sol.sortedListToBST(l);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

void test3() {
	Solution sol;
	int arr[] = {1,2,3,4,5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	ListNode* l = getList(v);
	TreeNode* res = sol.sortedListToBST(l);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

void test4() {
	Solution sol;
	int arr[] = {1,2,3,4,5,6,6,7,8,9,10};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	ListNode* l = getList(v);
	TreeNode* res = sol.sortedListToBST(l);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

void test5() {
	Solution sol;
	int arr[] = {1,1,2,3,4,5,6,6,7,8,9,10};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	ListNode* l = getList(v);
	TreeNode* res = sol.sortedListToBST(l);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

int main() {
	//test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	/*test6();
	test7();*/
	return 0;
}