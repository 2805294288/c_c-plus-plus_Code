class MinStack {
public:
    /** initialize your data structure here. */
    
    void push(int val) {
        if(MinStack.empty() || val <= MinStack.top())
        {
            MinStack.push(val);
        }

        st.push(val);
    }
    
    void pop() {
        if(st.top() == MinStack.top())
        {
            MinStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return MinStack.top();
    }
private:
    stack<int> st;
    stack<int> MinStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */