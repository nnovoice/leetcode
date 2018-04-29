/*
Leetcode: 821. Shortest Distance to a Character
Given a string S and a character C, return an array of integers representing the shortest distance from the character C in the string.

Example 1:

Input: S = "loveleetcode", C = 'e'
Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]


Note:

S string length is in [1, 10000].
C is a single character, and guaranteed to be in string S.
All letters in S and C are lowercase.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        unordered_map<char,vector<int>> locs;
        for (int i = 0; i < S.length(); ++i) {
            locs[S[i]].push_back(i);
        }

        vector<int> res;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == C) res.push_back(0);
            else {
                int minDist = INT_MAX, curDist = 0;
                for (int j = 0; j < locs[C].size(); ++j) {
                    curDist = locs[C][j] - i;
                    curDist = (curDist < 0) ? (0 - curDist) : curDist;
                    if (curDist > minDist) break;
                    minDist = curDist;
                }
                res.push_back(minDist);
            }
        }
        return res;
    }
};

void printVector(std::vector<int>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

void test0() {
    Solution s;
    std::vector<int> v1 = s.shortestToChar("loveleetcode", 'l');
    vector<int> expected = {0, 1, 2, 1, 0, 1, 2, 3, 4, 5, 6, 7};
    printVector(v1);
    printVector(expected);
    assert(v1 == expected);
}

void test1() {
    Solution s;
    std::vector<int> v1 = s.shortestToChar("loveleetcode", 'e');
    vector<int> expected = {3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0};
    printVector(v1);
    printVector(expected);
    assert(v1 == expected);
}

void test2() {
    Solution s;
    std::vector<int> v1 = s.shortestToChar("eeleeoeveleeeteceode", 'e');
    vector<int> expected = {0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0};
    printVector(v1);
    printVector(expected);
    assert(v1 == expected);
}

int main()
{
    test0();
    test1();
    test2();
/*  test3();
    test4();
*/
    return 0;
}
