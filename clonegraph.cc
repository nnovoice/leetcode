/**
Leetcode: 133. Clone Graph
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
 */
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <cassert>
#include <iostream>
using namespace std;

struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
  };

typedef UndirectedGraphNode UGN;

class Solution {
public:
    UGN *cloneGraph(UGN *node) {
        if (node == nullptr) return node;

        map<int, UGN*> outmap;
        unordered_set<int> visited;
        queue<UGN*> nodesQ;

        UGN *n = nullptr;
        nodesQ.push(node);

        while (nodesQ.empty() == false) {
            n = nodesQ.front();
            nodesQ.pop();
            //cout << "popped= " << n->label << endl;
            
            if (visited.find(n->label) == visited.end()) {
                //cout << "not found node= " << n->label << endl;
                UGN *n1 = outmap[n->label];
                if (n1 == nullptr) {
                    //cout << "label=" << n->label << " did not exist. Creating." << endl;
                    n1 = new UGN(n->label);
                    outmap[n->label] = n1;
                }

                for (UGN *c : n->neighbors) {
                    UGN *c1 = outmap[c->label];
                    if (c1 == nullptr) {
                        c1 = new UGN(c->label);
                        outmap[c->label] = c1;
                    }
                    n1->neighbors.push_back(c1);
                    //c1->neighbors.push_back(n1);
                    
                    nodesQ.push(c);
                }
                
                visited.insert(n->label);
            }
        }
        //cout << "end of clone graph\n";
        return outmap[node->label];
    }
};

void printGraph(UGN *node) {
    if (node == nullptr) return;
    
    queue<UGN *> nodesQ;
    map<int, UGN*> nodesMap;
    nodesQ.push(node);
    UGN* n = nullptr;

    while (nodesQ.empty() == false) {
        n = nodesQ.front();
        nodesQ.pop();
        if (nodesMap[n->label] == nullptr) {
            cout << n->label << " ->";

            for (UGN *nn : n->neighbors) {
                cout << " " << nn->label; 
                nodesQ.push(nn);
            }
            cout << endl;

            nodesMap[n->label] = n;
        }
    }
}

void test0() {
    UGN *a = nullptr;
    Solution sol;
    printGraph(a);
    UGN *aNew = sol.cloneGraph(a);
    printGraph(aNew);
}

void test1() {
    UGN *a = new UGN(0);
    UGN *b = new UGN(1);
    
    a->neighbors.push_back(b);
    b->neighbors.push_back(a);
    
    Solution sol;
    printGraph(a);
    UGN *aNew = sol.cloneGraph(a);
    printGraph(aNew);
}

void test2() {
    UGN *a = new UGN(0);
    UGN *b = new UGN(1);
    UGN *c = new UGN(2);
    UGN *d = new UGN(3);

    a->neighbors.push_back(b);
    a->neighbors.push_back(c);
    a->neighbors.push_back(d);

    b->neighbors.push_back(a);
    c->neighbors.push_back(a);
    d->neighbors.push_back(a);

    Solution sol;
    printGraph(a);
    UGN *aNew = sol.cloneGraph(a);
    printGraph(aNew);
}

void test3() {
    UGN *a = new UGN(0);
    UGN *b = new UGN(1);
    UGN *c = new UGN(2);
    
    a->neighbors.push_back(b);
    a->neighbors.push_back(c);

    b->neighbors.push_back(a);
    b->neighbors.push_back(c);

    c->neighbors.push_back(a);
    c->neighbors.push_back(b);
    c->neighbors.push_back(c);

    Solution sol;
    printGraph(a);
    UGN *aNew = sol.cloneGraph(a);
    printGraph(aNew);
}


int main() {
    test0();
    test1();
    test2();
    test3();
    return 0;
}