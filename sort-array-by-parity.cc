/*
Leetcode: 905. Sort Array by Parity
https://leetcode.com/problems/sort-array-by-parity/
Easy
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size() - 1;
        while (i < j) {
            while (i < j && ((A[i] % 2) == 0)) ++i;
            while (i < j && ((A[j] % 2) == 1)) --j;
            //cout << i << " " << j << " " << A[i] << " " << A[j] << endl;
            if (i < j) {
                swap(A[i], A[j]);
                ++i;
                --j;
            }
        }
        return A;
    }
};

void printVector(const vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void test0() {
    std::vector<int> v = {1,2,3,4};
    std::vector<int> e = {4,2,3,1};
    Solution sol;
    std::vector<int> res = sol.sortArrayByParity(v);
    printVector(e);
    printVector(res);
    //assert(e == res);
}

int main() {
    test0();
    return 0;
}