/*
202. Happy Number

Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

*/
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int sumSquares = 0, digit = 0, t = 0;
        while (n > 9) {
            //if (n == 1) break;
            //cout << n << " ";
            t = n;
            sumSquares = 0;
            while (t != 0) {
                digit = t % 10;
                sumSquares += (digit * digit);
                t /= 10;
            }
            n = sumSquares;
        }
        // cout << endl;
        return (n == 1 || n == 7) ? true : false;
    }
};

void experiment0() {
    Solution sol;
    bool happy = false;
    for (int i = 0; i <= 10000; ++i) {
        happy = sol.isHappy(i);
        cout << "i= " << i << " isHappy=" << happy << endl;
    }
}

void test0() {
    Solution s;

    bool res = s.isHappy(19);
    assert(res == true);
}

void test1() {
    Solution s;
    bool res = s.isHappy(20);
    assert(res == false);
}

int main() {
    //experiment0();
    test0();
    test1();
    return 0;
}