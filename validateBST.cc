/*
Leetcode: 98
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
#include <vector>
#include <stack>
#include <utility>
#include <iostream>
#include <cassert>
using namespace std;

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
	void traverseInorder(vector<int>& v, TreeNode* root) {
		if (root == NULL) return;
		traverseInorder(v, root->left);
		v.push_back(root->val);
		traverseInorder(v, root->right);
	}
public:
    bool isValidBST(TreeNode* root) {
    	std::vector<int> v;
    	traverseInorder(v, root);
    	int n = v.size();
    	for (int i = 1; i < n; ++i) {
    		if (v[i] > v[i - 1]) continue;
    		else return false;
    	}
    	return true;
    }
};

void test0() {
	Solution sol;
	bool res = sol.isValidBST(NULL);
	assert (res == true);
}

void test1() {
	Solution sol;
	TreeNode* root = new TreeNode(101);
	bool res = sol.isValidBST(root);
	assert (res == true);
}

void test2() {
	Solution sol;
	TreeNode* root = new TreeNode(2);
	
	TreeNode* rootl = new TreeNode(1);
	TreeNode* rootr = new TreeNode(3);
	root->left = rootl;
	root->right = rootr;
	
	bool res = sol.isValidBST(root);
	cout << "test2=" << res << endl;
	assert (res == true);
}

void test3() {
	Solution sol;
	TreeNode* root = new TreeNode(4);
	
	TreeNode* rootl = new TreeNode(3);
	root->left = rootl;

	TreeNode* ll = new TreeNode(2);
	rootl->left = ll;

	TreeNode* lll = new TreeNode(1);
	ll->left = lll;

	bool res = sol.isValidBST(root);
	cout << "test3=" << res << endl;
	assert (res == true);
}

void test4() {
	Solution sol;
	TreeNode* root = new TreeNode(4);
	
	TreeNode* l = new TreeNode(2);
	root->left = l;

	TreeNode* ll = new TreeNode(1);
	l->left = ll;

	TreeNode* lr = new TreeNode(3);
	l->right = lr;

	bool res = sol.isValidBST(root);
	cout << "test4=" << res << endl;
	assert (res == true);
}

void test5() {
	Solution sol;
	TreeNode* root = new TreeNode(4);
	
	TreeNode* l = new TreeNode(2);
	root->left = l;

	TreeNode* r = new TreeNode(7);
	root->right = r;

	TreeNode* ll = new TreeNode(1);
	l->left = ll;

	TreeNode* lr = new TreeNode(5);
	l->right = lr;

	bool res = sol.isValidBST(root);
	cout << "test5=" << res << endl;
	assert (res == false);
}

void test6() {
	Solution sol;
	TreeNode* root = new TreeNode(4);
	
	TreeNode* l = new TreeNode(2);
	root->left = l;

	TreeNode* r = new TreeNode(7);
	root->right = r;

	TreeNode* ll = new TreeNode(1);
	l->left = ll;

	TreeNode* lr = new TreeNode(4);
	l->right = lr;

	bool res = sol.isValidBST(root);
	cout << "test6=" << res << endl;
	assert (res == false);
}


int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	return 0;
}