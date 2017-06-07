/*
Leetcode: 111
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.


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
        if (root == NULL) return 0;
        d += 1;
        if (root->left == NULL && root->right == NULL) return d;
        int ld = INT_MAX, rd = INT_MAX;
        if (root->left) ld = depth (d, root->left);
        if (root->right) rd = depth (d, root->right);
        return min(ld, rd);
    }    
public:
    int minDepth(TreeNode* root) {
        //if (root == NULL) return 0;
        return depth (0, root);

    }
};

void test0() {
	Solution sol;
	int res = sol.minDepth(NULL);
	assert (res == 0);
}

void test1() {
	Solution sol;
	TreeNode* root = new TreeNode(101);
	int res = sol.minDepth(root);
	assert (res == 1);
}

void test2() {
	Solution sol;
	TreeNode* root = new TreeNode(2);
	
	TreeNode* rootl = new TreeNode(1);
	TreeNode* rootr = new TreeNode(3);
	root->left = rootl;
	root->right = rootr;
	
	int res = sol.minDepth(root);
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

	int res = sol.minDepth(root);
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

	int res = sol.minDepth(root);
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

	int res = sol.minDepth(root);
	cout << "test5=" << res << endl;
	assert (res == 2);
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

	int res = sol.minDepth(root);
	cout << "test6=" << res << endl;
	assert (res == 2);
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