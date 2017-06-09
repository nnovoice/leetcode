/*
Leetcode: 108
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
	TreeNode* sortedArrayToBST(vector<int>& nums, int low, int high) {
    	if (low > high) return NULL;
        int median = low + (high - low) / 2;
        TreeNode* root = new TreeNode(nums[median]);
        root->left = sortedArrayToBST(nums, low, median - 1);
        root->right = sortedArrayToBST(nums, median + 1, high);
        return root;
    }    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return sortedArrayToBST (nums, 0, nums.size() - 1);
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

void test0() {
	Solution sol;
	int arr[] = {};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	TreeNode* res = sol.sortedArrayToBST(v);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

void test1() {
	Solution sol;
	int arr[] = {1};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	TreeNode* res = sol.sortedArrayToBST(v);
	//assert (res == true);
}

void test2() {
	Solution sol;
	int arr[] = {1,2,3,4};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	TreeNode* res = sol.sortedArrayToBST(v);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

void test3() {
	Solution sol;
	int arr[] = {1,2,3,4,5};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	TreeNode* res = sol.sortedArrayToBST(v);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

void test4() {
	Solution sol;
	int arr[] = {1,2,3,4,5,6,6,7,8,9,10};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	TreeNode* res = sol.sortedArrayToBST(v);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

void test5() {
	Solution sol;
	int arr[] = {1,1,2,3,4,5,6,6,7,8,9,10};
	std::vector<int> v (arr, arr + (sizeof(arr)/sizeof(int)));
	TreeNode* res = sol.sortedArrayToBST(v);
	std::vector<int> v1 (getSortedArray(res));  
	assert (v == v1);
}

int main() {
	test0();
	test1();
	test2();
	test3();
	test4();
	test5();
	/*test6();
	test7();*/
	return 0;
}