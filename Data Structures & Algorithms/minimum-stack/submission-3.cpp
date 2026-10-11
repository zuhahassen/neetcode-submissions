class MinStack {
public:
    stack<long> minStack; 
    long minN; 

    MinStack() {
    }
    
    void push(int val) {
        if (minStack.empty()) {
            minStack.push(0);
            minN = val;
        } else {
            minStack.push(val - minN); 
            minN = min((long)val, minN); 
        }
    }
    
    void pop() {
        if (minStack.empty()) return; 
        long pop = minStack.top(); 

        minStack.pop();

        if (pop < 0) minN = minN - pop; 
    }
    
    int top() {
        long top = minStack.top();

        return (top > 0) ? (top + minN) : (int)minN; 
    }
    
    int getMin() {
        return (int)minN;
    }
};
