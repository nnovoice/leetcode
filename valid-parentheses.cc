#include <string>
#include <stack>
#include <map>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if (n == 0 || ((n % 2) != 0)) return false;
        map<char,char> matches;
        //char 
        matches[')'] = '(';
        matches['}'] = '{';
        matches[']'] = '[';

        stack<char> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if (st.empty()) return false;
                if (st.top() != matches[s[i]]) return false;
                st.pop();
            }
        }
        if (st.empty()) return true;
        return false;
    }
};

void test0() {
    Solution sol;
    string s = "";
    bool res = sol.isValid(s);
    assert (res == false);
} 

void test1() {
    Solution sol;
    string s = "(({{[[]]}}))";
    bool res = sol.isValid(s);
    assert (res == true);
} 

void test2() {
    Solution sol;
    string s = "(({{[[]]}}))(){}[]";
    bool res = sol.isValid(s);
    assert (res == true);
} 

void test3() {
    Solution sol;
    string s = "(({{[[]]}}))(){}[](";
    bool res = sol.isValid(s);
    assert (res == false);
} 

void test4() {
    Solution sol;
    string s = "(({{[[]]}}))(){}[](";
    bool res = sol.isValid(s);
    assert (res == false);
}

void test5() {
    Solution sol;
    string s = "(({{[[]]}}))(){}[])(";
    bool res = sol.isValid(s);
    assert (res == false);
}

void test6() {
    Solution sol;
    string s = "(({{[[]]}}))(){}[][)(]";
    bool res = sol.isValid(s);
    assert (res == false);
}

void test7() {
    Solution sol;
    string s = "(({{[[]]}}))(){}[][({)}]";
    bool res = sol.isValid(s);
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
    test7();
    return 0;
}
