class MinStack {
public:
//pair values in stack (first,second) = (val,minVal)
stack<pair<int,int>> minSt;

    MinStack() {
        
    }
    
    void push(int val) {
        if(minSt.empty()) minSt.push({val,val});
        else {
            int minVal = min(val,minSt.top().second);
            minSt.push({val,minVal});
            }
    }
    
    void pop() {
        minSt.pop();
    }
    
    int top() {
        return minSt.top().first;
    }
    
    int getMin() {
        return minSt.top().second;
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