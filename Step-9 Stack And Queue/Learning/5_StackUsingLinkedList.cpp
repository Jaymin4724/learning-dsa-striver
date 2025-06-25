// struct StackNode {
//     int data;
//     StackNode* next;
//     StackNode(int x) : data(x), next(NULL) {}
// };

class MyStack
{
private:
    StackNode *top;

public:
    // push : d
    // a <- b <- c(top)

    void push(int x)
    {
        StackNode *newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
    }
    // After Push Operation
    // a <- b <- c <- d(top)

    int pop()
    {
        if (top == NULL)
            return -1; // Stack is empty

        int value = top->data;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    MyStack() { top = NULL; }
};
