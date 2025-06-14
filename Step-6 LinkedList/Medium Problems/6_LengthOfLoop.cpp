#include <bits/stdc++.h>
using namespace std;

// Using Hashing / Using Maps
// TC : O(N)
// SC : O(N)
int lengthOfLoopBruteForce(ListNode *head)
{
    if (!head)
        return 0;
    unordered_map<ListNode *, int> mpp;
    ListNode *temp = head;
    while (temp)
    {
        mpp[temp]++;
        if (mpp[temp] > 1)
        {
            // Loop detected, now count the length
            ListNode *loopNode = temp;
            int length = 1;
            temp = temp->next;
            while (temp != loopNode)
            {
                length++;
                temp = temp->next;
            }
            return length;
        }
        temp = temp->next;
    }
    return 0; // No loop found
}

//? Tortoise and Hare Algorithm (using slow & fast pointers)
// TC : O(N)
// SC : O(1)
ListNode *lengthOfLoopOptimal(ListNode *head)
{
    ListNode *slow, *fast;
    slow = fast = head;
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
            fast = slow->next;
            int length = 1;
            while (fast != slow)
            {
                length++;
                fast = fast->next;
            }
        }
        return length;
    }
}
return 0;
}