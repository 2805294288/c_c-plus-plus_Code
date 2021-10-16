class Solution {
public:
    void push(int value) {
        st1.push(value);
        if(st2.empty() || value <= st2.top())
        {
            st2.push(value);
        }
    }
    void pop() {
        if(st1.top() == st2.top())
            st2.pop();
        st1.pop();
    }
    int top() {
        return st1.top();
    }
    int min() {
        return st2.top();
    }
public:
    stack<int> st1;
    stack<int> st2;
};