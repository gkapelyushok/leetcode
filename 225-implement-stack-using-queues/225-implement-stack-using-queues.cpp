class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        peek = x;
        q.push(x);
    }
    
    int pop() {
        int size = q.size();
        for (int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
        int res = q.front();
        q.pop();
        peek = q.back();
        return res;
    }
    
    int top() {
        return peek;
    }
    
    bool empty() {
        return q.empty();
    }
    
private:
    queue<int> q;
    int peek;
};

//1 2 3 4
//4 1 2 3
//3 4 1 2
//2 3 4 

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */