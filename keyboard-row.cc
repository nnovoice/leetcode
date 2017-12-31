/*
Leetcode: 500. Keyboard Row
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
Example 1:
Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
Note:
You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.

*/

#include <unordered_map>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

class Solution {
private:
    unordered_map<char, int> charMap;
private:
    void buildCharMap(vector<string>& words) {
        vector<string> rows = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};        
        int i = 0;
        for (string row : rows) {
            for (int j = 0; j < row.size(); ++j) {
                charMap[row[j]] = i;
                charMap['a'+ row[j] - 'A'] = i;
            }
            ++i;
        }
    }
    vector<string> filterWords(vector<string>& words) {
        vector<string> res;
        int rNum = 0;
        bool match = true;
        for (string word : words) {
            match = true;
            rNum = charMap[word[0]];
            for (int j = 0; j < word.size(); ++j) {
                if (rNum != charMap[word[j]]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                res.push_back(word);    
            }
        }
        return res;
    }
public:
    vector<string> findWords(vector<string>& words) {
        buildCharMap(words);
        return filterWords(words);        
        
    }
};

int main() {
	vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
	vector<string> expected = {"Alaska", "Dad"};
	vector<string> res;
	Solution sol;
	res = sol.findWords(words);
	assert (res == expected);

	return 0;
}
