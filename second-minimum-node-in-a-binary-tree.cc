/*
Leetcode 671. Second Minimum Node In a Binary Tree
Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:
Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
Example 2:
Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.
*/
#include <set>
#include <iostream>
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
    set<int> values;
private:
    void buildSecondMinimumValue(TreeNode* root) {
        if (root->left != nullptr && root->right != nullptr) {
            buildSecondMinimumValue(root->left);
            values.insert(root->val);
            buildSecondMinimumValue(root->right);
        }
        else {
            values.insert(root->val);
        }
    }  
    int getSecondMaximum() {
        if (values.size() <= 1) return -1;
        int i = 0;
        for (std::set<int>::iterator it=values.begin(); it!=values.end(); ++it, ++i) {
            if (i == 1) return *it;
        }
        return -1;
    }
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr) return -1;
        buildSecondMinimumValue(root);
        return getSecondMaximum();
    }
};

int main() {
    return 0;
}