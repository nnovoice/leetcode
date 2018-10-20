/*
Leetcode: 832. Flipping an image
https://leetcode.com/problems/flipping-an-image/submissions/
Easy
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
#include <cassert>
using namespace std;


class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0, k = A[i].size() - 1; j < k; ++j, --k) {
                swap(A[i][j], A[i][k]);
                A[i][j] = (A[i][j] == 0) ? 1 : 0;
                A[i][k] = (A[i][k] == 0) ? 1 : 0;
            }
            // flip if the # of elems is odd. 
            if (n % 2 == 1) {
                A[i][n/2] = (A[i][n/2] == 0) ? 1 : 0;
            }
        }
        return A;
    }
};

void printMatrix(const vector<vector<int>>& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

}

void test0() {
    std::vector<vector<int>> v = {{1,0,1},{1,1,0},{1,1,1}};
    Solution sol;
    std::vector<vector<int>> res = sol.flipAndInvertImage(v);
    printMatrix(v);    
}

int main() {
    test0();
    return 0;
}