#include <bits/stdc++.h>
using namespace std;

// BruteForce Solution
// TC : O(N)
// SC : O(1)
ListNode *deleteMiddleBruteForce(ListNode *head)
{
    ListNode *temp = head;
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    int res = n / 2;
    temp = head;
    while (temp != NULL)
    {
        res--;
        if (res == 0)
        {
            ListNode *middle = temp->next;
            temp->next = temp->next->next;
            free(middle);
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Tortoise & Hare using Slow & Fast Pointers
// TC : O(N)
// SC : O(1)
ListNode *deleteMiddleOptimal(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    fast = head->next->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = slow->next->next;
    return head;
}
