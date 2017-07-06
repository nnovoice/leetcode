/*
Leetcode: 22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

*/
#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

void printVector(vector<string>& v) {
    for (auto a : v) 
        cout << a << " ";
    cout << endl;
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0) return res;
        map<string, int> current, next;
        map<string, int>::iterator it;
        current["()"] = 1; // populate the first one
        for (int i = 2; i <= n; ++i) {
            for (it = current.begin(); it != current.end(); ++it) {
                string s = it->first;
                for (int i = 0; i < s.length(); ++i) {
                    string n = "";
                    for (int j = 0; j < i; ++j) {
                        n += s[j];
                    }
                    n += "()";
                    //i + 1 to end
                    for (int k = i; k < s.length(); ++k) {
                        n += s[k];
                    }
                    next[n] = 1;
                }
            }
            current = next;
            next = map<string,int>();
        }
        
        for (it = current.begin(); it != current.end(); ++it) {
            res.push_back(it->first);
        }
        return res;
    }
};

void test0() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(0);
    assert (res.size() == 0);
} 

void test1() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(1);
    assert (res.size() == 1 && res[0] == "()");
} 

void test2() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(2);
    vector<string> exp = {"()()", "(())"};
    printVector(res);
    //assert (res == exp);
} 

void test3() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(3);
    vector<string> exp = {"()()()", "()(())", "(())()", "((()))", "(()())"};
    printVector(res);
    //assert (res == exp);
} 
void test4() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(4);
    vector<string> exp = {"()()()", "()(())", "(())()", "((()))", "(()())"};
    printVector(res);
    //assert (res == exp);
} 

void test5() {
    Solution sol;
    vector<string> res = sol.generateParenthesis(10);
    vector<string> exp = {"()()()", "()(())", "(())()", "((()))", "(()())"};
    printVector(res);
    //assert (res == exp);
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
