/*
    Leetcode: 84. Largest Rectangle in Histogram
    Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
    */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <climits>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0, curArea = 0, minHeight = 0, nBars = 0;
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            minHeight = heights[i];
            nBars = 0;
            for (int j = i; j < n; ++j) {
                if (heights[j] == 0) {
                    nBars = 0;
                }
                else {
                    nBars += 1;
                    if (minHeight > heights[j]) minHeight = heights[j];
                    curArea = minHeight * nBars;
                    maxArea = max(maxArea, curArea);
                }
            }
        }
        return maxArea;
    }
};

    void test1() {
    Solution s;
    std::vector<int> v = {2,1,5,6,2,3};
    int res = s.largestRectangleArea(v);
    cout << res << endl;
    assert(res == 10);
    }

    void test2() {
    Solution s;
    std::vector<int> v = {20, 19, 1, 10, 5, 15, 12, 17, 3, 2, 90};
    int res = s.largestRectangleArea(v);
    cout << res << endl;
    assert(res == 90);
    }

    void test3() {
    Solution s;
    std::vector<int> v = {0, 0, 0, 0};
    int res = s.largestRectangleArea(v);
    cout << res << endl;
    assert(res == 0);
    }

    void test4() {
    Solution s;
    std::vector<int> v = {20};
    int res = s.largestRectangleArea(v);
    cout << res << endl;
    assert(res == 20);
    }

    void test5() {    
    Solution s;
    std::vector<int> v = {1, 0, 1, 2, 1, 4};
    int res = s.largestRectangleArea(v);
    cout << res << endl;
    
	assert(res == 4);
    }


    void test6() {    
    Solution s;
    std::vector<int> v = {1,2,3,4,5,6,7};
    int res = s.largestRectangleArea(v);
    cout << res << endl;
    assert(res == 16);
    }

    int main()
    {
    test1();
    test2(); 
    test3();   
    test4();
    test5();
    test6();
    return 0;
    }
