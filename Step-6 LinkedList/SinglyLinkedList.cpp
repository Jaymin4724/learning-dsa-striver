#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Singly Linked List class with all required operations
class SinglyLinkedList
{
    Node *head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // --- Insertion Functions ---
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int val, int pos)
    {
        if (pos <= 1)
        {
            insertAtBeginning(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 1; temp != nullptr && i < pos - 1; ++i)
            temp = temp->next;
        if (temp == nullptr)
        {
            cout << "Position out of bounds. Inserting at end.\n";
            insertAtEnd(val);
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // --- Deletion Functions ---
    void deleteAtBeginning()
    {
        if (head == nullptr)
            return;
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
    }

    void deleteAtEnd()
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *prev = nullptr;
        Node *curr = head;
        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }
        delete curr;
        prev->next = nullptr;
    }

    void deleteByValue(int val)
    {
        if (head == nullptr)
            return;
        if (head->data == val)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr && temp->next->data != val)
            temp = temp->next;
        if (temp->next != nullptr)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    void deleteByPosition(int pos)
    {
        if (head == nullptr)
            return;
        if (pos <= 1)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        for (int i = 1; temp->next != nullptr && i < pos - 1; ++i)
            temp = temp->next;
        if (temp->next != nullptr)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // --- Other Functions ---
    bool search(int val)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }

    int length()
    {
        int len = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            ++len;
            temp = temp->next;
        }
        return len;
    }

    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~SinglyLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    SinglyLinkedList list;
    int choice, val, pos;
    do
    {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete by Value\n";
        cout << "5. Delete by Position\n";
        cout << "6. Search\n";
        cout << "7. Find Length\n";
        cout << "8. Display List\n";
        cout << "9. Delete at Beginning\n";
        cout << "10. Delete at End\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> val >> pos;
            list.insertAtPosition(val, pos);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteByValue(val);
            break;
        case 5:
            cout << "Enter position to delete: ";
            cin >> pos;
            list.deleteByPosition(pos);
            break;
        case 6:
            cout << "Enter value to search: ";
            cin >> val;
            cout << (list.search(val) ? "Found\n" : "Not Found\n");
            break;
        case 7:
            cout << "Length: " << list.length() << endl;
            break;
        case 8:
            list.display();
            break;
        case 9:
            list.deleteAtBeginning();
            cout << "Deleted at beginning.\n";
            break;
        case 10:
            list.deleteAtEnd();
            cout << "Deleted at end.\n";
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
