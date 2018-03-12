/*
451. Sort Characters By Frequency

Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
private:
    struct compare {
      bool operator()(const pair<char,int> l, const pair<char,int> r) {
          return l.second < r.second;
      }
    };
public:
    string frequencySort(string s) {
        unordered_map<char,int> counts;
        for (int i = 0; i < s.length(); ++i) {
            counts[s[i]] += 1;
        }

        priority_queue<pair<char,int>, vector<pair<char,int>>, compare> maxHeap;
        for (unordered_map<char,int>::iterator iter = counts.begin(); iter != counts.end(); ++iter) {
            maxHeap.push(make_pair(iter->first, iter->second));
        }

        int i = 0, count = 0;
        char c = ' ';
        while(maxHeap.empty() == false) {
            pair<char,int> elem = maxHeap.top();
            maxHeap.pop();

            c = elem.first;
            count = elem.second;

            for (int j = 0; j < count; ++j) {
                s[i++] = c;
            }
        }
        //cout << "s=" << s << endl;
        return s;
    }
};

void test0() {
    Solution sol;
    string s = "abc";
    string r = sol.frequencySort(s);
    assert(r == "abc" || r == "acb" || r == "cab" || r == "cba" || r == "bac" || r == "bca");
}

void test0_1() {
    Solution sol;
    string s = "Z";
    string r = sol.frequencySort(s);
    assert(r == "Z");
}

void test1() {
    Solution sol;
    string s = "abaca";
    string r = sol.frequencySort(s);
    assert(r == "aaabc" || r == "aaacb");
}

void test2() {
    Solution sol;
    string s = "tree";
    string r = sol.frequencySort(s);
    assert(r == "eert" || r == "eetr");
}

void test3() {
    Solution sol;
    string s = "acacaccacaca";
    string r = sol.frequencySort(s);
    assert(r == "aaaaaacccccc" || r == "ccccccaaaaaa");
}

void test4() {
    Solution sol;
    string s = "Abab";
    string r = sol.frequencySort(s);
    assert(r == "bbAa" || r == "bbaA");
}

int main()
{
    test0();
    test0_1();
    test1();
    test2();
    test3();
    test4();
    return 0;
}
