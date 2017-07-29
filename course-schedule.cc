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
    map<int,bool> vertices;
    unordered_set<int> path;
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
    bool dfs(int n) {
        stack<int> dfsStack;
        dfsStack.push(n);
        while (dfsStack.empty() == false) {
            int n = dfsStack.top();
            path.insert(n);
            for (int pre : graph[n]) {
                if (vertices[pre]) continue;
                if (path.find(pre) != path.end()) return false;
                dfsStack.push(pre);
            }

            if (dfsStack.top() == n) {
                vertices[n] = true;
                path.erase(n);
                dfsStack.pop();
            }
        }
        return true;
    }
    bool canFinish(int n) {
        for (int i = 0; i < n; ++i) {
            vertices = map<int, bool>();
            path = unordered_set<int>();
            bool b = dfs(i);
            if (b == false) return false;
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
    std::vector<pair<int,int>> v = {};
    Solution sol;
    bool res = sol.canFinish(0, v);
    assert(res == true);
}

void test0_1() {
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
void test6() {
    //8
    // [[1,0],[2,6],[1,7],[6,4],[7,0],[0,5]]
    std::vector<pair<int,int>> v = {make_pair(1,0), make_pair(2,6), 
        make_pair(1,7),make_pair(6,4),make_pair(7,0), make_pair(0,5),
        make_pair(7,4), make_pair(6,1), make_pair(4,6)};
    Solution sol;
    bool res = sol.canFinish(5,v);
    assert(res == false);
}

int main() {
    test0();
    test0_1();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}