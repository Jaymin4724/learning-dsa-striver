#include <bits/stdc++.h>
using namespace std;

// BruteForce
// TC : O(N)
// SC : O(N)
ListNode *oddEvenListBruteForce(ListNode *head)
{
    if (!head || !head->next)
        return head;

    vector<int> odd, even;

    // Step 1: Traverse and separate values
    ListNode *temp = head;
    int pos = 1;
    while (temp)
    {
        if (pos % 2 == 1)
            odd.push_back(temp->val);
        else
            even.push_back(temp->val);
        temp = temp->next;
        pos++;
    }

    // Step 2: Overwrite node values
    temp = head;
    for (int val : odd)
    {
        temp->val = val;
        temp = temp->next;
    }
    for (int val : even)
    {
        temp->val = val;
        temp = temp->next;
    }

    return head;
}

// Optimal Solution
// TC : O(N)
// SC : O(1)
ListNode *oddEvenListOptimal(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = head->next;
    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}