/*
Leetcode: 680. Valid Palindrome II 
Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

Example 1:
Input: "aba"
Output: True
Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.
Note:
The string will only contain lowercase characters a-z. The maximum length of the string is 50000.

*/
#include <iostream>
#include <unordered_map>
#include <string>
#include <cassert>
using namespace std;
class MapSum {
private:
    unordered_map<string,int> counts;    
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        string t = "";
        int n = key.size() - 1;
        for (int i = 0; i < n; ++i) {
            t += key[i];
            counts[t] += val;
        }
        counts[key] = val;
    }
    
    int sum(string prefix) {
        return counts[prefix];
    }
};


void test0() {
    MapSum s;
    s.insert("apple",2);
    s.insert("app", 3);
    assert(s.sum("ap") == 5);
}

void test1() {
    MapSum s;
    s.insert("apple",2);
    s.insert("app", 3);
    s.insert("orange", 100);
    s.insert("orangutan", 100);
    assert(s.sum("orang") == 200);
}

int main() {
    test0();
    test1();
    /*test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();*/
    return 0;
}