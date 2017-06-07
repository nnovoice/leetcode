/*
Leetcode: 337
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.
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