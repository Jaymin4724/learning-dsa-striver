// Function to push an integer into the stack.

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack::push(int x)
{
    if (top >= 999) // Max index = 999 for size 1000
        return;
    top++;
    arr[top] = x;
}

int MyStack::pop()
{
    if (top == -1) // Stack is empty
        return -1;
    int val = arr[top];
    top--;
    return val;
}