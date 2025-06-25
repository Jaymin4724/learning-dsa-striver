/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

// push : d
// (front)a -> b -> c(rear)
void MyQueue::push(int x)
{
    QueueNode *newNode = new QueueNode(x);

    if (rear == NULL)
    {
        // Queue is empty
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}
// (front)a->b->c->d(rear)

int MyQueue ::pop()
{
    if (front == NULL)
    {
        // Queue is empty
        return -1;
    }
    QueueNode *temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL)
    {
        // Queue became empty after pop
        rear = NULL;
    }

    delete temp;
    return val;
}
