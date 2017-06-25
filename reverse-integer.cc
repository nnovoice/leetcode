/*
7. Reverse Integer
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
Next challenges: 
(H) Max Points on a Line
(E) Missing Number
(M) Convex Polygon

*/
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <cassert>
using namespace std;


class Solution {
public:
     int reverse(int x) {
        long long int num = 0;
        int sign = (x < 0) ? -1 : 1;
        x = (sign == 1) ? x : (0 - x);
        while (x != 0) {
            num *= 10;
            num += (x % 10);
            x /= 10;
        }
        if (num > INT_MAX || num < INT_MIN) return 0;
        return (int) (sign * num);
    }
};

 
void test0() {
    Solution sol;
    int res = sol.reverse(10);
    assert (res == 1);
}

void test1() {
    Solution sol;
    int res = sol.reverse(0);
    assert (res == 0);
}

void test1_1() {
    Solution sol;
    int res = sol.reverse(INT_MAX);
    assert (res == 0);
}

void test2() {
    Solution sol;
    int res = sol.reverse(INT_MIN);
    assert (res == 0);
}

void test3() {
    Solution sol;
    int res = sol.reverse(1234567);
    assert (res == 7654321);
}

void test4() {
    Solution sol;
    int res = sol.reverse(-1012);
    assert (res == -2101);
}

void test5() {
    Solution sol;
    int res = sol.reverse(65535);
    assert (res == 53556);
}

void test6() {
    Solution sol;
    int res = sol.reverse(135790);
    assert (res == 97531);
}

void test7() {
    Solution sol;
    int res = sol.reverse(67584930);
    assert (res == 3948576);
}

int main() {
    test0();
    test1();
    test1_1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}
