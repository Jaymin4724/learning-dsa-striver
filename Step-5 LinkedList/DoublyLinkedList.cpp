#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAtPosition(int val, int pos)
    {
        if (pos <= 1)
        {
            insertAtBeginning(val);
            return;
        }
        Node *temp = head;
        int cnt = 1;
        while (temp && cnt < pos - 1)
        {
            temp = temp->next;
            cnt++;
        }
        if (!temp || !temp->next)
        {
            insertAtEnd(val);
            return;
        }
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteAtBeginning()
    {
        if (!head)
            return;
        Node *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteAtEnd()
    {
        if (!tail)
            return;
        Node *temp = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }

    void deleteAtPosition(int pos)
    {
        if (pos <= 1)
        {
            deleteAtBeginning();
            return;
        }
        Node *temp = head;
        int cnt = 1;
        while (temp && cnt < pos)
        {
            temp = temp->next;
            cnt++;
        }
        if (!temp)
            return;
        if (temp == tail)
        {
            deleteAtEnd();
            return;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
    }

    bool search(int val)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    int length()
    {
        int cnt = 0;
        Node *temp = head;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void displayForward()
    {
        Node *temp = head;
        cout << "Forward: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void displayReverse()
    {
        Node *temp = tail;
        cout << "Reverse: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    ~DoublyLinkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }
};

int main()
{
    DoublyLinkedList dll;
    int choice, val, pos;
    while (true)
    {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n";
        cout << "7. Search\n8. Length\n9. Display Forward\n10. Display Reverse\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            dll.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            dll.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> val >> pos;
            dll.insertAtPosition(val, pos);
            break;
        case 4:
            dll.deleteAtBeginning();
            break;
        case 5:
            dll.deleteAtEnd();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            dll.deleteAtPosition(pos);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (dll.search(val) ? "Found\n" : "Not Found\n");
            break;
        case 8:
            cout << "Length: " << dll.length() << endl;
            break;
        case 9:
            dll.displayForward();
            break;
        case 10:
            dll.displayReverse();
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
