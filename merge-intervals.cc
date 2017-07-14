/*
Leetcode: 56. Merge Intervals
Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool areIntervalVectorsEqual(vector<Interval>& l, vector<Interval>& r) {
	if (l.size() != r.size()) return false;
	//cout << "l.size=" << l.size() << " r.size=" << r.size() << endl;
	for (int i = 0; i < l.size(); ++i) {
		//cout << r[i].start << " " << r[i].end << endl;
		if (l[i].start != r[i].start || l[i].end != r[i].end) return false;
	}
	return true;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
    	vector<Interval> res;
    	int n = intervals.size();
    	if (n == 0) return res;

    	Interval cur (intervals[0].start, intervals[0].end);
        for (int i = 0; i < n; ++i) {
        	if (intervals[i].start > cur.end) {
        		res.push_back(cur);
        		//cout << cur.start << " " << cur.end << endl;
        		cur.start = intervals[i].start;
        		cur.end = intervals[i].end;
        	}
        	else { // obvious that (intervals[i].start <= cur.end)
        		if (intervals[i].end > cur.end)
        			cur.end = intervals[i].end;
        		if (intervals[i].start < cur.start)
        			cur.start = intervals[i].start;
        	}
        }
        res.push_back(cur);
        //cout << cur.start << " " << cur.end << endl;
        return res;
    }
};

void test0() {
	Solution sol;
	std::vector<Interval> v1 = {};
	std::vector<Interval> res = sol.merge(v1);
	assert (res.size() == 0);
}

void test1() {
	Solution sol;
	std::vector<Interval> v1 = {Interval(1,5), Interval(1,10), Interval(2,8)};
	std::vector<Interval> exp = {Interval(1,10)};
	std::vector<Interval> res = sol.merge(v1);
	assert (areIntervalVectorsEqual(exp,res) == true);
}

void test1_1() {
	Solution sol;
	std::vector<Interval> v1 = {Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18)};
	std::vector<Interval> exp = {Interval(1,6), Interval(8,10), Interval(15,18)};
	std::vector<Interval> res = sol.merge(v1);
	//Given [1,3],[2,6],[8,10],[15,18],
	//return [1,6],[8,10],[15,18].
	assert (areIntervalVectorsEqual(exp,res) == true);
}

void test1_2() {
	Solution sol;
	//[[1,3],[2,6],[8,10],[15,18],[14,19]]
	std::vector<Interval> v1 = {Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18), Interval(14,19)};
	std::vector<Interval> exp = {Interval(1,6), Interval(8,10), Interval(14,19)};
	std::vector<Interval> res = sol.merge(v1);
	//Given [1,3],[2,6],[8,10],[15,18],
	//return [1,6],[8,10],[15,18].
	assert (areIntervalVectorsEqual(exp,res) == true);
}

void test1_3() {
	Solution sol;
	std::vector<Interval> v1 = {Interval(1,5), Interval(1,8), 
		Interval(2,6), Interval(2,10), Interval(3,11), Interval(3,18)};
	std::vector<Interval> exp = {Interval(1,18)};
	std::vector<Interval> res = sol.merge(v1);
	assert (areIntervalVectorsEqual(exp,res) == true);
}

void test2() {
	Solution sol;
	std::vector<Interval> v1 = {Interval(1,3), Interval(4,6), Interval(7,10), Interval(15,18)};
	std::vector<Interval> exp = {Interval(1,3), Interval(4,6), Interval(7,10), Interval(15,18)};
	std::vector<Interval> res = sol.merge(v1);
	assert (areIntervalVectorsEqual(exp,res) == true);
}

void test3() {
	Solution sol;
	std::vector<Interval> v1 = {Interval(1,3), Interval(2,6), Interval(7,10), Interval(9,18)};
	std::vector<Interval> exp = {Interval(1,6), Interval(7,18)};
	std::vector<Interval> res = sol.merge(v1);
	assert (areIntervalVectorsEqual(exp,res) == true);
}



int main() {
	test0();
	test1();
	test1_1();
	test1_2();
	test1_3();
	test2();
	test3();
	/*test4();
	test5();*/
	/*test6();
	test7();*/
	return 0;
}