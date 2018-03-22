/*
263. Ugly Number

Write a program to check whether a given number is an ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.

Note:

1 is typically treated as an ugly number.
Input is within the 32-bit signed integer range.

*/
#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
//        if (num < 0) {
//            num = 0 - num;
//        }

        vector<int> factors = {2, 3, 5};
        for (int i = 0; i < factors.size(); ++i) {
            while ((num > 1) && (num % factors[i] == 0)) {
                num /= factors[i];
                //cout << " " << num;
            }
        }
        return (num == 1) ? true : false;
    }
};

void experiment0() {
    Solution sol;
    bool ugly = false;
    for (int i = 0; i <= 10000; ++i) {
        ugly = sol.isUgly(i);
        cout << " i= " << i << " isUgly=" << ugly << endl;
    }
}

void test0() {
    Solution s;
    bool res = s.isUgly(1);
    assert(res == true);
}

void test1() {
    Solution s;
    bool res = s.isUgly(20);
    assert(res == true);
}

void test2() {
    Solution s;
    bool res = s.isUgly(21);
    assert(res == false);
}

int main() {
    //experiment0();
    test0();
    test1();
    test2();
    return 0;
}