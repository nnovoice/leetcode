/*
692. Top K Frequent Words
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <string>
using namespace std;

void printVector(std::vector<string>& v) {
    cout << "printVector\n";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

class Solution {
private:
    struct compare {
      bool operator()(const pair<string,int> l, const pair<string,int> r) {
          return l.second < r.second;
      }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> counts;
        for (int i = 0; i < words.size(); ++i)
            counts[words[i]] += 1;

        priority_queue<pair<string,int>, vector<pair<string,int>>, compare> maxHeap;
        for (unordered_map<string,int>::iterator iter = counts.begin(); iter != counts.end(); ++iter) {
            maxHeap.push(make_pair(iter->first, iter->second));
        }

        vector<string> topKElements;
        vector<string> currentElements;
        int freq = maxHeap.top().second;
        pair<string, int> elem;
        while (maxHeap.empty() == false) {
            elem = maxHeap.top();
            if (elem.second != freq) {
                sort(begin(currentElements), end(currentElements));
                topKElements.insert(std::end(topKElements), std::begin(currentElements), std::end(currentElements));
                currentElements = vector<string>();
                freq = elem.second;
            }
            currentElements.push_back(elem.first);
            maxHeap.pop();
        }
        if (currentElements.size() > 0) {
            sort(begin(currentElements), end(currentElements));
            topKElements.insert(std::end(topKElements), std::begin(currentElements), std::end(currentElements));
        }
        return vector<string>(begin(topKElements), begin(topKElements) + k);
    }
};



void test0() {
    Solution s;
    std::vector<string> words = {"i"};
    printVector(words);
    vector<string> topKElements = s.topKFrequent(words, 1);
    printVector(topKElements);
    assert(topKElements.size() == 1 && topKElements[0] == "i");
}

void test0_1() {
    Solution s;
    std::vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    printVector(words);
    vector<string> topKElements = s.topKFrequent(words, 2);
    printVector(topKElements);
    assert(topKElements.size() == 2 && topKElements[0] == "i" && topKElements[1] == "love");
}

void test1() {
    Solution s;
    std::vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    std::vector<string> expected = {"the", "is", "sunny", "day"};
    printVector(words);
    vector<string> topKElements = s.topKFrequent(words, 4);
    printVector(topKElements);
    assert(topKElements == expected);
}

void test2() {
    Solution s;
    std::vector<string> words = {"om", "ramana", "om", "ramana", "om", "ramana", "namo", "ramana", "namo"};
    std::vector<string> expected = {"ramana", "om", "namo"};
    printVector(words);
    vector<string> topKElements = s.topKFrequent(words, 3);
    printVector(topKElements);
    assert(topKElements == expected);
}

void test3() {
    Solution s;
    std::vector<string> words = {"om", "ramana", "om", "ramana", "om", "ramana", "namo", "ramana", "namo", "bhagavathe", "bhagavathe", "bhagavathe"};
    std::vector<string> expected = {"ramana", "bhagavathe", "om", "namo"};
    printVector(words);
    vector<string> topKElements = s.topKFrequent(words, 4);
    printVector(topKElements);
    assert(topKElements == expected);
}

void test4() {
    Solution s;
    std::vector<string> words = {"om", "sri", "ramana", "sri",
        "om", "ramana", "sri", "om", "ramana", "sri", "namo",
        "ramana", "namo", "bhagavathe", "bhagavathe", "bhagavathe"};
    std::vector<string> expected = {"ramana", "sri", "bhagavathe", "om"};
    printVector(words);
    vector<string> topKElements = s.topKFrequent(words, 4);
    printVector(topKElements);
    assert(topKElements == expected);
}

void test5() {
    Solution s;
    std::vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    std::vector<string> expected = {"i"};
    printVector(words);
    vector<string> topKElements = s.topKFrequent(words, 1);
    printVector(topKElements);
    assert(topKElements == expected);
}


int main()
{
    test0();
    test0_1();
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}
