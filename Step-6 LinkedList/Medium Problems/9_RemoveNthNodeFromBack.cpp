#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(1)
ListNode *removeNthFromEndBruteForce(ListNode *head, int n)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    ListNode *temp = head;

    // Count the number of nodes in the linked list
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    // If N equals the total number of
    // nodes, delete the head
    if (cnt == n)
    {
        ListNode *newhead = head->next;
        delete (head);
        return newhead;
    }

    // Calculate the position of the node to delete (res)
    int res = cnt - n;
    temp = head;

    // Traverse to the node just before the one to delete
    while (temp != NULL)
    {
        res--;
        if (res == 0)
        {
            break;
        }
        temp = temp->next;
    }

    // Delete the Nth node from the end
    ListNode *delNode = temp->next;
    temp->next = temp->next->next;
    delete (delNode);
    return head;
}

// Tortoise & Hare (Slow & Fast Pointers)
// TC : O(N)
// SC : O(1)
ListNode *removeNthFromEndOptimal(ListNode *head, int n)
{
    // Create two pointers, fastp and slowp
    ListNode *fastp = head;
    ListNode *slowp = head;

    // Move the fastp pointer N nodes ahead
    for (int i = 0; i < N; i++)
        fastp = fastp->next;

    // If fastp becomes NULL,
    // the Nth node from the end is the head
    if (fastp == NULL)
        return head->next;

    // Move both pointers until fastp reaches the end
    while (fastp->next != NULL)
    {
        fastp = fastp->next;
        slowp = slowp->next;
    }

    // Delete the Nth node from the end
    ListNode *delNode = slowp->next;
    slowp->next = slowp->next->next;
    delete delNode;
    return head;
}
