/*
Leetcode: 104
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
#include <vector>
#include <stack>
#include <climits>
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
    int depth(int d, TreeNode* root) {
        if (root == NULL) return d;
        d += 1;
        int ld = depth (d, root->left);
        int rd = depth (d, root->right);
        return max(d, max(ld, rd));
    }    
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        return depth (0, root);
    }
};

void test0() {
	Solution sol;
	int res = sol.maxDepth(NULL);
	assert (res == 0);
}

void test1() {
	Solution sol;
	TreeNode* root = new TreeNode(101);
	int res = sol.maxDepth(root);
	assert (res == 1);
}

void test2() {
	Solution sol;
	TreeNode* root = new TreeNode(2);
	
	TreeNode* rootl = new TreeNode(1);
	TreeNode* rootr = new TreeNode(3);
	root->left = rootl;
	root->right = rootr;
	
	int res = sol.maxDepth(root);
	cout << "test2=" << res << endl;
	assert (res == 2);
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

	int res = sol.maxDepth(root);
	cout << "test3=" << res << endl;
	assert (res == 4);
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

	int res = sol.maxDepth(root);
	cout << "test4=" << res << endl;
	assert (res == 3);
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

	int res = sol.maxDepth(root);
	cout << "test5=" << res << endl;
	assert (res == 3);
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

	int res = sol.maxDepth(root);
	cout << "test6=" << res << endl;
	assert (res == 3);
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