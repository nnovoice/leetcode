/*
Leetcode: 110
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/
#include <vector>
#include <stack>
#include <climits>
#include <utility>
#include <cstdlib>
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
    int depthBalanced(TreeNode* root) {
        if (root == NULL) return 0;
        
        int ld = depthBalanced (root->left);
        if (ld == -1) return -1;
        
        int rd = depthBalanced (root->right);
        if (rd == -1) return -1;
        
        if (abs(ld - rd) > 1) return -1;

        return max(ld, rd) + 1;
    }    
public:
    bool isBalanced(TreeNode* root) {
        int diff = depthBalanced(root);
        return (diff < 0 ? false : true);
    }
};

void test0() {
	Solution sol;
	int res = sol.isBalanced(NULL);
	assert (res == true);
}

void test1() {
	Solution sol;
	TreeNode* root = new TreeNode(101);
	int res = sol.isBalanced(root);
	assert (res == true);
}

void test2() {
	Solution sol;
	TreeNode* root = new TreeNode(2);
	
	TreeNode* rootl = new TreeNode(1);
	TreeNode* rootr = new TreeNode(3);
	root->left = rootl;
	root->right = rootr;
	
	int res = sol.isBalanced(root);
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

	int res = sol.isBalanced(root);
	cout << "test3=" << res << endl;
	assert (res == false);
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

	int res = sol.isBalanced(root);
	cout << "test4=" << res << endl;
	assert (res == false);
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

	int res = sol.isBalanced(root);
	cout << "test5=" << res << endl;
	assert (res == true);
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

	int res = sol.isBalanced(root);
	cout << "test6=" << res << endl;
	assert (res == true);
}

void test7() {
	Solution sol;
	TreeNode* root = new TreeNode(4);
	
	TreeNode* l = new TreeNode(2);
	root->left = l;

	TreeNode* r = new TreeNode(7);
	root->right = r;

	TreeNode* ll = new TreeNode(1);
	l->left = ll;

	TreeNode* lll = new TreeNode(4);
	ll->left = lll;

	TreeNode* llll = new TreeNode(4);
	lll->left = llll;

	TreeNode* lllr = new TreeNode(4);
	lll->right = lllr;

	int res = sol.isBalanced(root);
	cout << "test7=" << res << endl;
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
	test7();
	return 0;
}