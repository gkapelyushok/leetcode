class MinStack {
private:
    stack<int> vals;
    stack<int> mins;
public:
    MinStack() {
        
    }
    void push(int val) {
	    vals.push(val);
	    if (mins.empty() || mins.top() >= val) {
            mins.push(val);
        }    
    }
    
    void pop() {
        if (mins.top() == vals.top()) {
            mins.pop();
        }
	    vals.pop();
    }
    
    int top() {
	    return vals.top();
    }
    
    int getMin() {
	    return mins.top();
    }
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */