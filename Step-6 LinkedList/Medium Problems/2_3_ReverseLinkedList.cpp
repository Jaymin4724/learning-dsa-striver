#include <bits/stdc++.h>
using namespace std;

// Iterative BruteForce Approach : Iterate, push data into stack and then change data and pop
// TC : O(N)
// SC : O(N)
ListNode *reverseListIterativeBruteFroce(ListNode *head)
{
    if (!head)
        return nullptr;

    stack<int> s;
    ListNode *temp;
    temp = head;
    while (temp)
    {
        s.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        int data = s.top();
        temp->val = data;
        s.pop();
        temp = temp->next;
    }
    return head;
}

// Iterative Optimal Approach (Change the links)
// head->1->2->3->4->5->null
// null<-1<-2<-3<-4<-5<-head
// TC : O(N)
// SC : O(1)
ListNode *reverseListIterativeOptimal(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *curr = head, *prev = nullptr;
    while (curr != nullptr)
    {
        ListNode *front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

// Recursive Approach
// TC : O(N)
// SC : O(1)
ListNode *reverseListRecursive(ListNode *head)
{
    // base case
    if (!head || !head->next)
        return head;
    // recursive case
    ListNode *newHead = reverseList(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
