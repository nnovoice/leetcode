/*
Leetcode: 662. Maximum Width of Binary Tree
Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:
Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:
Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:
Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:
Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
*/
#include <vector>
#include <queue>
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
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode*,int>> current, next;
        pair<TreeNode*,int> node;
        current.push(make_pair(root, 1));
        int maxWidth = 0, l = 0, r = 0, id = 0;
        while (current.empty() == false) {
        	node = current.front();
        	l = node.second;
        	r = l;
        	while (current.empty() == false) {
        		node = current.front();
        		id = node.second;
        		r = id;
        		if (node.first->left) next.push(make_pair(node.first->left, 2 * id));
        		if (node.first->right) next.push(make_pair(node.first->right, 2 * id + 1));
        		current.pop();
        	}
        	maxWidth = max(maxWidth, r + 1 - l);
        	swap(current, next);
        }
        //cout << maxWidth << endl;
    	return maxWidth;   
    }
};

void test0() {
	Solution sol;
	int res = sol.widthOfBinaryTree(NULL);
	assert (res == 0);
}

void test1() {
	Solution sol;
	TreeNode* root = new TreeNode(101);
	int res = sol.widthOfBinaryTree(root);
	assert (res == 1);
}

void test2() {
	Solution sol;
	TreeNode* root = new TreeNode(2);
	
	TreeNode* rootl = new TreeNode(1);
	TreeNode* rootr = new TreeNode(3);
	root->left = rootl;
	root->right = rootr;
	
	int res = sol.widthOfBinaryTree(root);
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

	int res = sol.widthOfBinaryTree(root);
	cout << "test3=" << res << endl;
	assert (res == 1);
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

	int res = sol.widthOfBinaryTree(root);
	cout << "test4=" << res << endl;
	assert (res == 2);
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

	int res = sol.widthOfBinaryTree(root);
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

	TreeNode* rr = new TreeNode(4);
	r->right = rr;

	int res = sol.widthOfBinaryTree(root);
	cout << "test6=" << res << endl;
	assert (res == 4);
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

	TreeNode* lll = new TreeNode(1);
	ll->left = lll;

	TreeNode* lr = new TreeNode(4);
	l->right = lr;

	TreeNode* rr = new TreeNode(4);
	r->right = rr;

	TreeNode* rrr = new TreeNode(4);
	rr->right = rrr;

	int res = sol.widthOfBinaryTree(root);
	cout << "test7=" << res << endl;
	assert (res == 8);
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