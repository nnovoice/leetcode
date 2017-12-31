/*
Leetcode: 728. Self Dividing Numbers
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.

Example 1:
Input: 
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
*/
#include <vector>
#include <cassert>
using namespace std;

class Solution {
private:
    bool isSelfNumber(int n) {
        int digit = 0, nTemp = n;
        while (nTemp != 0) {
            digit = nTemp % 10;
            if (digit == 0) return false;
            if (n % digit != 0) return false;
            nTemp /= 10;
        }
        return true;
    }    
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> selves;
        bool isSelf = false;
        for (int n = left; n <= right; ++n) {
            isSelf = isSelfNumber(n);
            if (isSelf) selves.push_back(n);
        }
        return selves;
    }
};

void test0() {
    Solution s;
    std::vector<int> res = s.selfDividingNumbers(1,22);
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
    assert (res == expected);
}

int main() {
    test0();
    //test1();
    return 0;
}
