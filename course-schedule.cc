/**
Leetcode: 207. Course Schedule
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it 
possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have f
inished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, a
nd to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
 */
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <stack>
#include <cassert>
#include <iostream>
using namespace std;

class Solution {
private:
    map<int,vector<int>> graph;
private:
    void printGraph() {
        map<int,vector<int>>::iterator iter = graph.begin();
        for (; iter != graph.end(); ++iter) {
            int n = iter->first;
            cout << n << "->";
            for (int p : graph[n]) {
                cout << p << " ";
            }
            cout << endl;
        }
    }
    void addEdge(pair<int,int> p) {
        graph[p.second].push_back(p.first);
    }
    void buildGraph(vector<pair<int, int>>& prerequisites) {
        //Some courses may have prerequisites, for example to take course 0 
        // you have to first take course 1, 
        //which is expressed as a pair: [0,1] [x,y] y->x
        for (pair<int,int> p : prerequisites) {
            addEdge(p);
        }
    }
    void updateInfo(int cNum, unordered_set<int>& visited, unordered_set<int>&curVertices, stack<int>& dfsStack) {
        dfsStack.pop();
        visited.insert(cNum);
        curVertices.erase(cNum);
    }
    bool canFinish(int n) {
        unordered_set<int> visited, curVertices;
        stack<int> dfsStack;
        int cNum = 0;

        for (int i = 0; i < n; ++i) {
            if (visited.find(i) != visited.end()) continue;

            dfsStack.push(i);
            curVertices.insert(i);

            while (dfsStack.empty() == false) {
                cNum = dfsStack.top();

                vector<int>& preReqs = graph[cNum];
                if (preReqs.size() == 0)
                    updateInfo(cNum, visited, curVertices, dfsStack);
                else {
                    bool prereqsSatisfied = true;
                    for (int pre: preReqs) {
                        // is there a pre-req loop?
                        if (curVertices.find(pre) != curVertices.end()) return false;
                        if (visited.find(pre) == visited.end()) {
                            dfsStack.push(pre);
                            curVertices.insert(pre);
                            prereqsSatisfied = false;
                        }
                    }
                    if (prereqsSatisfied)
                        updateInfo(cNum, visited, curVertices, dfsStack);
                }
            }
        }
        return true;
    }
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        buildGraph(prerequisites);
        printGraph();
        return canFinish(numCourses);
    }
};


void test0() {
    std::vector<pair<int,int>> v = {make_pair(0,1)};
    Solution sol;
    bool res = sol.canFinish(2, v);
    assert(res == true);
}

void test1() {
    std::vector<pair<int,int>> v = {make_pair(0,1), make_pair(1,0)};
    Solution sol;
    bool res = sol.canFinish(2, v);
    assert(res == false);
}

void test2() {
    std::vector<pair<int,int>> v = {make_pair(0,1), make_pair(1,2), make_pair(2,3)};
    Solution sol;
    bool res = sol.canFinish(4,v);
    assert(res == true);
}

void test3() {
    std::vector<pair<int,int>> v = {make_pair(0,1), make_pair(1,2), make_pair(2,3)};
    Solution sol;
    bool res = sol.canFinish(4,v);
    assert(res == true);
}

void test4() {
    std::vector<pair<int,int>> v = {make_pair(0,1), make_pair(1,2), make_pair(2,3),make_pair(0,4),make_pair(1,3)};
    Solution sol;
    bool res = sol.canFinish(5,v);
    assert(res == true);
}
void test5() {
    //8
    // [[1,0],[2,6],[1,7],[6,4],[7,0],[0,5]]
    std::vector<pair<int,int>> v = {make_pair(1,0), make_pair(2,6), 
        make_pair(1,7),make_pair(6,4),make_pair(7,0), make_pair(0,5)};
    Solution sol;
    bool res = sol.canFinish(5,v);
    assert(res == true);
}

int main() {
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}