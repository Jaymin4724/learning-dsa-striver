#include <bits/stdc++.h>
using namespace std;
/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/

class Solution
{
public:
    // TC : O(N)
    // SC : O(1)
    ListNode *deleteAllOccurrencesOptimal(ListNode *head, int target)
    {
        if (!head)
            return nullptr;

        ListNode *curr = head;
        ListNode *prev = nullptr;

        while (curr)
        {
            if (curr->val == target)
            {
                LListNode *temp = curr;
                curr = curr->next;

                // Deleting head node
                if (temp == head)
                {
                    head = curr;
                    if (head)
                        head->prev = nullptr;
                }
                else
                {
                    prev->next = curr;
                    if (curr)
                        curr->prev = prev;
                }
                delete temp;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};