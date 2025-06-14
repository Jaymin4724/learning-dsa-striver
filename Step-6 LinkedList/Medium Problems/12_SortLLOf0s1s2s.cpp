#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // BruteForce
    // TC : O(NLOGN)
    // SC : O(N)
    // (1) TAKE AN ARRAY
    // (2) SORT IT
    // (3) OVERWRITE VALUES OF LINKEDLIST

    // Better
    // TC : O(N)
    // SC : O(1)
    ListNode *sortListBetter(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        int cnt0 = 0, cnt1 = 0, cnt2 = 0;
        ListNode *temp = head;

        // Count 0s, 1s, and 2s
        while (temp)
        {
            if (temp->val == 0)
                cnt0++;
            else if (temp->val == 1)
                cnt1++;
            else
                cnt2++;
            temp = temp->next;
        }

        // Overwrite values in the list
        temp = head;
        while (temp)
        {
            if (cnt0 > 0)
            {
                temp->val = 0;
                cnt0--;
            }
            else if (cnt1 > 0)
            {
                temp->val = 1;
                cnt1--;
            }
            else
            {
                temp->val = 2;
                cnt2--;
            }
            temp = temp->next;
        }

        return head;
    }

    // Optimal (Solution Without Data Replacement)
    // TC : O(N)
    // SC : O(1)
    ListNode *sortListOptimal(ListNode *head)
    {
        // Create 3 Dummy Nodes
        ListNode *dummy0 = new ListNode(-1);
        ListNode *dummy1 = new ListNode(-1);
        ListNode *dummy2 = new ListNode(-1);

        ListNode *temp0 = dummy0, *temp1 = dummy1, *temp2 = dummy2;
        ListNode *temp = head;
        while (temp)
        {
            if (temp->val == 0)
            {
                temp0->next = temp;
                temp0 = temp0->next;
            }
            else if (temp->val == 1)
            {
                temp1->next = temp;
                temp1 = temp1->next;
            }
            else
            {
                temp2->next = temp;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        // Connect the three lists
        temp0->next = dummy1->next ? dummy1->next : dummy2->next;
        temp1->next = dummy2->next;
        temp2->next = nullptr;

        head = dummy0->next;

        delete dummy0;
        delete dummy1;
        delete dummy2;

        return head;
    }
};
