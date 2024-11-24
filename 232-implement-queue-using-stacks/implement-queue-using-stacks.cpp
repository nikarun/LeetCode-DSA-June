class MyQueue {
public:
    stack<int>st1;
    stack<int>st2;
    MyQueue() {
        st1={};
        st2={};
    }
    
    void push(int x) {
        st1.push(x);  
    }

    int pop() {
        int top=-1;
        while(!st1.empty()){
            top=st1.top();
            st1.pop();
            if(!st1.empty()) st2.push(top);
        }
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return top;
    }
    
    int peek() {
        int top=-1;
        while(!st1.empty()){
            top=st1.top();
            st1.pop();
            st2.push(top);
        }
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        return top;
    }
    
    bool empty() {
        return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */