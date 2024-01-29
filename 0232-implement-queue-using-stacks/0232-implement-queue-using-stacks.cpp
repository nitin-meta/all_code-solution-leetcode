//Time Complexity: O(N) but Amortized O(1)
class MyQueue {
public:
    stack<int>input,output;
    int peekL=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(input.empty()){
            peekL=x;
        }
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){//yaha O(N) lag jayega
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        int val=output.top();//yha O(1)
        output.pop();
        return val;
    }
    
    int peek() {
        if(output.empty()) return peekL;
        return output.top();
    }
    
    bool empty() {
        return (input.empty()&&output.empty());
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