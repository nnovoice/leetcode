/*
Leetcode: 337
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.
*/
#include <vector>
#include <stack>
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
	int robTree(TreeNode* root) {
		vector<int> dp;
		dp.push_back(0);
		stack<TreeNode*>* parents  = new stack<TreeNode*>();
		stack<TreeNode*>* children = new stack<TreeNode*>();
		int level = 1;
		int num = 0;
		parents->push(root);
		while (parents->empty() == false) {
			TreeNode* t = parents->top();
			num += t->val;
			//cout << endl << t->val << " ";
			if (t->left != NULL)  {
				children->push(t->left);
				//cout << t->left->val << " ";
			}
			if (t->right != NULL) { 
				children->push(t->right);
				//cout << t->right->val << endl;
			}
			parents->pop();
			if (parents->empty()) {
				stack<TreeNode*>* temp = parents;
				parents = children;
				children = temp;
				//children = new stack<TreeNode*>();
				dp.push_back(num);
				num = 0;
				++level;
			}
		}
		/*cout << endl;
		for (int i = 0; i < dp.size(); ++i)
			cout << dp[i] << " ";
		cout << "level=" << level << endl;*/
		
		if (parents != NULL) delete parents;
		if (children != NULL) delete children;

		int idx2 = 0, idx3 = 0;
		for (int i = 2; i < level; ++i) {
			idx2 = i - 2;
			idx3 = i - 3;
			if (idx3 >= 0)
				dp[i] = dp[i] + max(dp[idx2], dp[idx3]);
			else
				dp[i] = dp[i] + dp[idx2];
		}
		return max(dp[level - 1], dp[level - 2]);
	}
public:
    int rob(TreeNode* root) {
    	if (root == NULL) return 0;
    	return robTree (root);
    }
};

void test0() {
	Solution sol;
	int res = sol.rob(0);
	assert (res == 0);
}

void test1() {
	Solution sol;
	TreeNode* root = new TreeNode(101);
	int res = sol.rob(root);
	assert (res == 101);
}

void test2() {
	Solution sol;
	TreeNode* root = new TreeNode(101);
	
	TreeNode* rootl = new TreeNode(2);
	TreeNode* rootr = new TreeNode(5);
	root->left = rootl;
	root->right = rootr;

	cout << root->val << " " << root->left->val << " " << root->right->val << endl;
	
	TreeNode* ll = new TreeNode(4);
	TreeNode* lr = new TreeNode(5);
	rootl->left = ll;
	rootl->right = lr;
	cout << rootl->val << " " << rootl->left->val << " " << rootl->right->val << endl;
	TreeNode* rl = new TreeNode(6);
	TreeNode* rr = new TreeNode(7);
	rootr->left = rl;
	rootr->right = rr;
	cout << rootr->val << " " << rootr->left->val << " " << rootr->right->val << endl;

	int res = sol.rob(root);
	cout << "test2=" << res << endl;
	assert (res == 123);
}

void test3() {
	Solution sol;
	TreeNode* root = new TreeNode(3);
	
	TreeNode* rootl = new TreeNode(2);
	TreeNode* rootr = new TreeNode(3);
	root->left = rootl;
	root->right = rootr;

	cout << root->val << " " << root->left->val << " " << root->right->val << endl;
	
	//TreeNode* ll = new TreeNode(4);
	TreeNode* lr = new TreeNode(3);
	//rootl->left = ll;
	rootl->right = lr;
	//cout << rootl->val << " " << rootl->left->val << " " << rootl->right->val << endl;
	//TreeNode* rl = new TreeNode(6);
	TreeNode* rr = new TreeNode(1);
	//rootr->left = rl;
	rootr->right = rr;
	//cout << rootr->val << " " << rootr->left->val << " " << rootr->right->val << endl;

	int res = sol.rob(root);
	cout << "test2=" << res << endl;
	assert (res == 7);
}

void test4() {
	Solution sol;
	TreeNode* root = new TreeNode(3);
	
	TreeNode* rootl = new TreeNode(4);
	TreeNode* rootr = new TreeNode(5);
	root->left = rootl;
	root->right = rootr;

	cout << root->val << " " << root->left->val << " " << root->right->val << endl;
	
	TreeNode* ll = new TreeNode(1);
	TreeNode* lr = new TreeNode(3);
	rootl->left = ll;
	rootl->right = lr;
	cout << rootl->val << " " << rootl->left->val << " " << rootl->right->val << endl;
	//TreeNode* rl = new TreeNode(6);
	TreeNode* rr = new TreeNode(1);
	//rootr->left = rl;
	rootr->right = rr;
	//cout << rootr->val << " " << rootr->left->val << " " << rootr->right->val << endl;

	int res = sol.rob(root);
	cout << "test2=" << res << endl;
	assert (res == 9);
}


int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	return 0;
}