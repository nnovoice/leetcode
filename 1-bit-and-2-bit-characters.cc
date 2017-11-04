/*
717. 1-bit and 2-bit Characters My SubmissionsBack to Contest
User Accepted: 1430
User Tried: 1566
Total Accepted: 1481
Total Submissions: 2942
Difficulty: Easy
We have two special characters. The first character can be represented by one bit 0. 
The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. 
Return whether the last character must be a one-bit character or not. 
The given string will always end with a zero.

Example 1:
Input: 
bits = [1, 0, 0]
Output: True
Explanation: 
The only way to decode it is two-bit character and one-bit character. 
So the last character is one-bit character.
Example 2:
Input: 
bits = [1, 1, 1, 0]
Output: False
Explanation: 
The only way to decode it is two-bit character and two-bit character. 
So the last character is NOT one-bit character.

*/
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        if (n == 0) return false;
        
        int i = 0, last = 0;;
        while (i < n) {
            if (bits[i] == 0) {
                ++i;
                last = 0;
            }
            else {
                if (i + 1 < n) {
                    i += 2;
                    last = 1;
                }
                else {
                    return false;
                }
            }
        }
        return (last == 0);
    }
};

void test0() {
    Solution s;
    std::vector<int> v = {1,0,0};
    bool res = s.isOneBitCharacter(v);
    assert(res == true);
}

void test1() {
    Solution s;
    std::vector<int> v = {1,1,1,0};
    bool res = s.isOneBitCharacter(v);
    assert(res == false);
}

int main() {
    test0();
    test1();
    return 0;
}