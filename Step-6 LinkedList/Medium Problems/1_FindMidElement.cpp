
#include <bits/stdc++.h>
using namespace std;

// Traverse n, Find the Length, Traver n/2
// TC : O(N)
// SC : O(1)
ListNode *middleNodeBruteForce(ListNode *head)
{
    int len;
    if (!head)
        return nullptr;
    if (!head->next)
        return head;
    ListNode *temp = head;
    len = 1;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        len++;
    }
    int mid = len / 2;
    temp = head;
    int count = 0;
    while (count < mid && temp != nullptr)
    {
        temp = temp->next;
        count++;
    }
    return temp;
}

//? Tortoise and Hare Algorithm (using slow & fast pointers)
// TC : O(N/2)
// SC : O(1)
ListNode *middleNodeOptimal(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
