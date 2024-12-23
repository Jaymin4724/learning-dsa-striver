// #include <iostream>
// #include <vector>
// #include <list>
// #include <deque>
// #include <queue>
// #include <stack>
// #include <set>
// #include <map>
// #include <unordered_set>
// #include <unordered_map>
// #include <algorithm>
#include <bits/stdc++.h> // Includes all the standard libraries
using namespace std;

// (1) Function to explain the usage of pairs in STL
void explain_pair()
{
    // Pair Declaration
    pair<int, int> p1 = {1, 3};
    // Nested pair
    pair<int, pair<int, int>> p2 = {1, {2, 3}};
    // Array pair
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

    cout << "\nLearning Pair : " << endl;
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;
    cout << arr[0].first << " " << arr[0].second << " " << arr[1].first << " " << arr[1].second << endl;
}

// (2) Function to explain the usage of vector in STL
void explain_vector()
{
    vector<int> v = {1, 2, 3};
    v.push_back(4); // Insert element at the end
    v.pop_back();   // Remove last element

    cout << "\nLearning Vector: " << endl;
    cout << "Vector elements: ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    // Inserting at a specific position using insert()
    v.insert(v.begin() + 1, 10); // Insert 10 at index 1
    cout << "Vector after inserting 10 at index 1: ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    // Removing elements using erase() - by position
    v.erase(v.begin() + 1); // Erase the element at index 1
    cout << "Vector after erase(): ";
    for (auto i : v)
        cout << i << " ";
    cout << endl;

    cout << "Vector empty() result: " << v.empty() << endl; // Check if vector is empty
    v.clear();                                              // Clear all elements
    cout << "Vector after clear(): Size = " << v.size() << endl;
}

// (3) Function to explain the usage of list in STL
void explain_list()
{
    list<int> l = {1, 2, 3};
    l.push_back(4);  // Insert element at the end
    l.push_front(0); // Insert element at the front

    cout << "\nLearning List: " << endl;
    cout << "List elements: ";
    for (auto i : l)
        cout << i << " ";
    cout << endl;

    l.sort(); // Sort the list
    cout << "List after sort(): ";
    for (auto i : l)
        cout << i << " ";
    cout << endl;

    // Insert using insert() at a specific position
    auto it = l.begin();
    advance(it, 2); // Move iterator to the 3rd position
    l.insert(it, 5);
    cout << "List after inserting 5 at 3rd position: ";
    for (auto i : l)
        cout << i << " ";
    cout << endl;

    // Erase an element using erase()
    l.erase(l.begin()); // Erase first element
    cout << "List after erase(): ";
    for (auto i : l)
        cout << i << " ";
    cout << endl;

    list<int> l2 = {5, 6};
    l.merge(l2); // Merge two lists
    cout << "List after merge(): ";
    for (auto i : l)
        cout << i << " ";
    cout << endl;

    l.clear(); // Clear all elements
    cout << "List after clear(): Size = " << l.size() << endl;
}

// (4) Function to explain the usage of deque in STL
void explain_deque()
{
    deque<int> dq = {1, 2, 3};
    dq.push_front(0); // Insert at the front
    dq.push_back(4);  // Insert at the end
    dq.pop_front();   // Remove from front

    cout << "\nLearning Deque: " << endl;
    cout << "Deque elements: ";
    for (auto i : dq)
        cout << i << " ";
    cout << endl;

    // Inserting at a specific position using insert()
    dq.insert(dq.begin() + 1, 100); // Insert 100 at index 1
    cout << "Deque after inserting 100 at index 1: ";
    for (auto i : dq)
        cout << i << " ";
    cout << endl;

    cout << "Element at index 1: " << dq.at(1) << endl; // Access element at index

    dq.clear(); // Clear all elements
    cout << "Deque after clear(): Size = " << dq.size() << endl;
}

// (5) Function to explain the usage of priority queue in STL
void explain_priority_queue()
{
    priority_queue<int> pq;
    pq.push(3); // Insert elements
    pq.push(1);
    pq.push(2);

    cout << "\nLearning Priority Queue (Max-Heap): " << endl;
    cout << "Priority Queue top: " << pq.top() << endl; // Get the top element (largest)

    // Custom comparator to create a Min-Heap
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(3);
    min_pq.push(1);
    min_pq.push(2);
    cout << "Learning Priority Queue (Min-Heap): " << endl;
    cout << "Min-Heap top: " << min_pq.top() << endl; // Get the top element (smallest)
}

// (6) Function to explain the usage of stack in STL
void explain_stack()
{
    stack<int> st;
    st.push(1); // Insert elements
    st.push(2);

    cout << "\nLearning Stack: " << endl;
    cout << "Stack top: " << st.top() << endl; // Get the top element

    // Check if stack is empty
    if (st.empty())
    {
        cout << "Stack is empty.\n";
    }
    else
    {
        cout << "Stack is not empty.\n";
    }
}

// (7) Function to explain the usage of queue in STL
void explain_queue()
{
    queue<int> q;
    q.push(1); // Insert elements
    q.push(2);

    cout << "\nLearning Queue: " << endl;
    cout << "Queue front: " << q.front() << endl; // Get the front element
    cout << "Queue back: " << q.back() << endl;   // Get the back element
}

// (8) Function to explain the usage of set in STL
void explain_set()
{
    set<int> s = {1, 2, 3};
    s.insert(4); // Insert elements

    cout << "\nLearning Set: " << endl;
    cout << "Set elements: ";
    for (auto i : s)
        cout << i << " ";
    cout << endl;

    // Lower and upper bound
    cout << "Lower bound of 2: " << *s.lower_bound(2) << endl;
    cout << "Upper bound of 2: " << *s.upper_bound(2) << endl;

    // Erasing elements by value and range
    s.erase(2); // Erase element by value
    cout << "Set after erasing 2: ";
    for (auto i : s)
        cout << i << " ";
    cout << endl;
}

// (9) Function to explain the usage of multiset in STL
void explain_multiset()
{
    multiset<int> ms = {1, 2, 2, 3};
    ms.insert(4); // Insert elements

    cout << "\nLearning Multiset: " << endl;
    cout << "Multiset elements: ";
    for (auto i : ms)
        cout << i << " ";
    cout << endl;

    // Count how many times an element appears
    cout << "Count of 2 in multiset: " << ms.count(2) << endl;
}

// (10) Function to explain the usage of unordered set in STL
void explain_unordered_set()
{
    unordered_set<int> us = {1, 2, 3};
    us.insert(4); // Insert elements

    cout << "\nLearning Unordered Set: " << endl;
    cout << "Unordered Set elements: ";
    for (auto i : us)
        cout << i << " ";
    cout << endl;

    us.emplace(5); // Efficient insertion
}

// (11) Function to explain the usage of map in STL
void explain_map()
{
    map<int, int> m;
    m[1] = 2;        // Insert key-value pairs
    m.emplace(2, 3); // Insert using emplace

    cout << "\nLearning Map: " << endl;
    cout << "Map elements: ";
    for (auto it : m)
        cout << "{" << it.first << ", " << it.second << "} ";
    cout << endl;

    // Find element using find()
    auto it = m.find(1); // Find the element with key 1
    if (it != m.end())
    {
        cout << "Found key 1 in the map.\n";
    }
    else
    {
        cout << "Key 1 not found in the map.\n";
    }

    // Erasing elements using erase()
    m.erase(1); // Erase element by key
    cout << "Map after erasing key 1: ";
    for (auto it : m)
        cout << "{" << it.first << ", " << it.second << "} ";
    cout << endl;
}

// (12) Function to explain the usage of multimap in STL
void explain_multimap()
{
    multimap<int, int> mm;
    mm.insert({1, 2});
    mm.insert({1, 3});
    mm.insert({2, 4});

    cout << "\nLearning Multimap: " << endl;
    cout << "Multimap elements: ";
    for (auto it : mm)
        cout << "{" << it.first << ", " << it.second << "} ";
    cout << endl;

    // Lower and upper bounds
    auto lb = mm.lower_bound(1);
    auto ub = mm.upper_bound(1);
    cout << "Lower bound for key 1: (" << lb->first << ", " << lb->second << ")" << endl;
    cout << "Upper bound for key 1: (" << ub->first << ", " << ub->second << ")" << endl;
}

int main()
{
    explain_pair();
    explain_vector();
    explain_list();
    explain_deque();
    explain_priority_queue();
    explain_stack();
    explain_queue();
    explain_set();
    explain_multiset();
    explain_unordered_set();
    explain_map();
    explain_multimap();
    return 0;
}
