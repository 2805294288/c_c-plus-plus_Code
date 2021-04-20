class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = que1.size();
        n--;
        while(n--)
        {
            que2.push(que1.front());
            que1.pop();
        }

        while(!que2.empty())
        {
            que1.push(que2.front());
            que2.pop();
        }

        int ret = que1.front();
        que1.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return que1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(que1.empty())
        {
            return true;
        }
        else
        return false;
    }
private:
    queue<int>  que1;
    queue<int>  que2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */