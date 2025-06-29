class MyQueue
{
public:
    stack<int> s1, s2;
    MyQueue() {}

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        while (!s1.empty())
        {
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        int val = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            int temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return val;
    }

    int peek()
    {
        while (!s1.empty())
        {
            int temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        int val = s2.top();
        while (!s2.empty())
        {
            int temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return val;
    }

    bool empty()
    {
        return s1.empty();
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