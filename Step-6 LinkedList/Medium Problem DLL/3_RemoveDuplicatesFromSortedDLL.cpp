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
    // TC: O(N)
    // SC: O(N)
    ListNode *removeDuplicatesBruteForce(ListNode *head)
    {
        if (!head)
            return nullptr;

        unordered_map<int, int> count;
        ListNode *curr = head;

        // Count all node values
        while (curr)
        {
            count[curr->val]++;
            curr = curr->next;
        }

        curr = head;
        while (curr)
        {
            ListNode *nextNode = curr->next;

            if (count[curr->val] > 1)
            {
                // Remove current node
                if (curr->prev)
                    curr->prev->next = curr->next;
                else
                    head = curr->next;

                if (curr->next)
                    curr->next->prev = curr->prev;

                delete curr;
            }

            curr = nextNode;
        }

        return head;
    }

    // TWO POINTERS APPROACH (LL IS SORTED, DUPLICATES WILL BE ADJACENT)
    // TC: O(N)
    // SC: O(1)
    ListNode *removeDuplicatesBruteForce(ListNode *head)
    {
        if (!head)
            return nullptr;

        ListNode *curr = head;
        while (curr && curr->next)
        {
            if (curr->val == curr->next->val)
            {
                // Duplicate found: remove next node
                ListNode *dup = curr->next;
                curr->next = dup->next;

                if (dup->next)
                    dup->next->prev = curr;

                delete dup;
            }
            else
            {
                curr = curr->next;
            }
        }

        return head;
    }
};
