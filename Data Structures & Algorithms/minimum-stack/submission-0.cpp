class MinStack {
private:
    stack<int> nums;
    stack<int> min;
public:
    MinStack() {}
    
    void push(int val) {
        nums.push(val);

        if(min.empty()){
            min.push(val);
        } else if(val <= min.top()){
            min.push(val);
        } else{
            min.push(min.top());
        }

    }
    
    void pop() {
        nums.pop();
        min.pop();
    }
    
    int top() {
        return nums.top();
        
    }
    
    int getMin() {
        return min.top();
    }
};
