#include <bits/stdc++.h>
using namespace std;

// Using Hashing / Using Map
// TC : O(N)
// SC : O(N)
ListNode *detectCycleStartingPointBruteForce(ListNode *head)
{
    if (!head)
        return nullptr;
    unordered_map<ListNode *, int> mpp;
    ListNode *temp = head;
    while (temp->next)
    {
        mpp[temp]++;
        if (mpp[temp] > 1)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

//? Tortoise and Hare Algorithm (using slow & fast pointers)
// TC : O(N)
// SC : O(1)
ListNode *detectCycleStartingPointOptimal(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // or return fast;
        }
    }
    return nullptr;
}