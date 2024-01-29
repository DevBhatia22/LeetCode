class MyQueue {
private:
    std::stack<int> main, notMain;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!main.empty()){
            notMain.push(main.top());
            main.pop();
        }
        main.push(x);
        while(!notMain.empty()){
            main.push(notMain.top());
            notMain.pop();
        }
    }
    
    int pop() {
        int answer = main.top();
        main.pop();
        return answer;
    }
    
    int peek() {
        int answer = main.top();
        return answer;
    }
    
    bool empty() {
        return main.empty();
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