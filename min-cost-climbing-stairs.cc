/*
746. Min Cost Climbing Stairs
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

*/

#include <vector>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int c1 = cost[0], c2 = cost[1], c3 = 0;
        for (int i = 2; i < n; ++i) {
            c3 = cost[i] + min(c1, c2);
            c1 = c2;
            c2 = c3;
        }
        return min(c1, c2);
    }
};

void test0() {
    Solution sol;
    vector<int> v = {10, 15, 20};
    int cost = sol.minCostClimbingStairs(v);
    assert(cost == 15);
}

void test1() {
    Solution sol;
    vector<int> v = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int cost = sol.minCostClimbingStairs(v);
    assert(cost == 6);
}

void test2() {
    Solution sol;
    vector<int> v = {10, 15};
    int cost = sol.minCostClimbingStairs(v);
    assert(cost == 10);
}

void test3() {
    Solution sol;
    vector<int> v = {100, 15, 150, 21, 22, 21};
    int cost = sol.minCostClimbingStairs(v);
    cout << cost << endl;
    assert(cost == 57);
}

int main() {
    test0();
    test1();
    test2();
    test3();
    //test4();
    return 0;
}