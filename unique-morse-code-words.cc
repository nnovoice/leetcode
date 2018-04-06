/*
804. Unique Morse Code Words

International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: "a" maps to ".-", "b" maps to "-...", "c" maps to "-.-.", and so on.

For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.

Return the number of different transformations among all words we have.

Example:
Input: words = ["gin", "zen", "gig", "msg"]
Output: 2
Explanation:
The transformation of each word is:
"gin" -> "--...-."
"zen" -> "--...-."
"gig" -> "--...--."
"msg" -> "--...--."

There are 2 different transformations, "--...-." and "--...--.".
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> charMap = {".-","-...","-.-.","-..",".","..-.",
                "--.","....","..",".---","-.-",".-..","--","-.","---",
                ".--.","--.-",".-.","...","-","..-","...-",".--","-..-",
                "-.--","--.."};
        unordered_set<string> uniqueReps;
        
        string s;
        for (string w : words) {
            s = "";
            for (int i = 0; i < w.length(); ++i) {
                s += charMap[w[i] - 'a'];
            }
            uniqueReps.insert(s);
        }
        return uniqueReps.size();
    }
};


void test0() {
    Solution s;
    std::vector<string> words = {"gin", "zen", "gig", "msg"};
    int uniqueElements = s.uniqueMorseRepresentations(words);
    cout << uniqueElements << endl;
    assert(uniqueElements == 2);
}

void test0_1() {
    Solution s;
    std::vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int uniqueElements = s.uniqueMorseRepresentations(words);
    cout << uniqueElements << endl;
    assert(uniqueElements == 4);
}

void test2() {
    Solution s;
    std::vector<string> words = {};
    char c = 'a';
    string str = "";
    for (int i = 0; i < 26; ++i) {
        str += (c + i);
        words.push_back(str);
        str = "";
    }
    int uniqueElements = s.uniqueMorseRepresentations(words);
    cout << uniqueElements << endl;
    assert(uniqueElements == 26);
}

int main()
{
    test0();
    test0_1();
    test2();
    return 0;
}
