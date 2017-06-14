/*
Leetcode 235. Lowest Common Ancestor of a Binary Search Tree
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
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
    int sumOfLeftLeaves(TreeNode *root, bool isLeft) {
        if (root == NULL) return 0;
        if (isLeft && root->left == NULL && root->right == NULL)
            return root->val;
        int leftVal = sumOfLeftLeaves(root->left, true);
        int rightVal = sumOfLeftLeaves(root->right, false);
        return leftVal + rightVal;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, false);
    }
};

int main() {
	return 0;
}