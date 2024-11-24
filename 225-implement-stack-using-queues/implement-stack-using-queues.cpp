class MyStack {
public:
    queue<int>q1;
    queue<int>q2;

    MyStack() {
        // q1.clear();
        q1={};
        q2={};
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        if(q1.empty()) return -1;
        int top;
        while(!q1.empty()){
            top=q1.front();
            q1.pop();
            if(!q1.empty()) q2.push(top);
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return top;
    }
    
    int top() {
        int top;
        while(!q1.empty()){
            top=q1.front();
            q2.push(top);
            q1.pop();
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return top;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */