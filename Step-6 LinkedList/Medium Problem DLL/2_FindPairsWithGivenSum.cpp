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
    // Nested Loop Approach
    // TC : O(N^2)
    // SC : O(N)
    vector<pair<int, int>> pairsWithGivenSumBruteForce(ListNode *head, int sum)
    {
        if (!head)
            return {};

        vector<pair<int, int>> answer;
        // You can use While Loop also
        for (ListNode *p = head; p; p = p->next)
            for (ListNode *q = p->next; q; q = q->next)
                if (p->val + q->val == sum)
                    answer.emplace_back(p->val, q->val);

        return answer;
    }

    //? DLL must be **sorted ascending**
    // TC : O(N)
    // SC : O(1)
    vector<pair<int, int>> pairsWithGivenSumOptimal(ListNode *head, int target)
    {
        vector<pair<int, int>> ans;
        if (!head || !head->next)
            return ans;

        // 1. left = head, right = tail
        ListNode *left = head, *right = head;
        while (right->next)
            right = right->next;

        // 2. two‑pointer scan
        while (left != right && right->next != left) // pointers have not crossed
        {
            int cur = left->val + right->val;

            if (cur == target)
            {
                ans.emplace_back(left->val, right->val);
                left = left->next;
                right = right->prev; // move both after recording
            }
            else if (cur < target)
            {
                left = left->next; // need larger sum
            }
            else
            {                        // cur > target
                right = right->prev; // need smaller sum
            }
        }
        return ans; // time: Θ(N), extra space: O(1) besides output
    }
}