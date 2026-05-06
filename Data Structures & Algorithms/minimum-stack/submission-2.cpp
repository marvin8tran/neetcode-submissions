class MinStack {
private:
    stack<int> min;
    stack<int> n;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(n.empty()){
            min.push(val);
        } else{
            if(min.top() < val){min.push(min.top());} 
            else{min.push(val);}
        }
        n.push(val);
    }
    
    void pop() {
        min.pop();
        n.pop();
    }
    
    int top() {
        return n.top();
    }
    
    int getMin() {
        return min.top();
    }
};
