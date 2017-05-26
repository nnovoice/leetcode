#include <stack>
#include <iostream>
#include <cassert>
using namespace std;

class MinStack {
private:
    stack<int> st; // actual stack
    stack<int> ms; // stack containing min elements only
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        st.push(x);
        if (ms.empty()) {
            ms.push(x);
            return;
        }

        if (ms.top() > x) {
            ms.push(x);
        }
        else {
            ms.push(ms.top());
        }
    }
    
    void pop() {
        if (st.empty() == false) {
            st.pop();
            ms.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return ms.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 */
void test0() {
    MinStack obj;
    obj.push(10);
    obj.push(20);
    //obj.pop();
    //int param_3 = obj.top();
    int p4 = obj.getMin();
    assert (p4 == 10);
    obj.push(1);
    assert (obj.getMin() == 1);
    obj.push(-1);
    obj.push(-1);
    assert (obj.getMin() == -1);
    obj.pop();
    assert (obj.getMin() == -1);
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
    obj.pop();
} 

int main() {
    test0();
    return 0;
}