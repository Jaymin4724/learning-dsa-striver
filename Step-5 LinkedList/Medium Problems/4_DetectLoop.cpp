#include <bits/stdc++.h>
using namespace std;

// Using Hashing / Using Map
// TC : O(N)
// SC : O(N)
bool hasCycleBruteForce(ListNode *head)
{
    if (!head)
        return false;
    unordered_map<ListNode *, int> mpp;
    ListNode *temp = head;
    while (temp)
    {
        mpp[temp]++;
        if (mpp[temp] > 1)
            return true;
        temp = temp->next;
    }
    return false;
}

//? Tortoise and Hare Algorithm (using slow & fast pointers)
// TC : O(N)
// SC : O(1)
bool hasCycleOptimal(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}