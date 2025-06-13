#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution
{
public:
    // BruteForce (Using Hashing)
    // TC : O(N)
    // SC : O(N)
    ListNode *getIntersectionNodeBruteForce(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> nodes;
        while (headA)
        {
            nodes.insert(headA);
            headA = headA->next;
        }
        while (headB)
        {
            if (nodes.count(headB))
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }

    // Better (Find Length, Find Difference and start together)
    // TC : O(N)
    // SC : O(1)
    ListNode *getIntersectionNodeBruteForce(ListNode *headA, ListNode *headB)
    {
        int lenA = 0, lenB = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;

        // Calculate lengths of both lists
        while (tempA)
        {
            lenA++;
            tempA = tempA->next;
        }
        while (tempB)
        {
            lenB++;
            tempB = tempB->next;
        }

        // Reset pointers
        tempA = headA;
        tempB = headB;

        // Align both pointers to the same starting point
        if (lenA > lenB)
        {
            int diff = lenA - lenB;
            while (diff--)
                tempA = tempA->next;
        }
        else
        {
            int diff = lenB - lenA;
            while (diff--)
                tempB = tempB->next;
        }

        // Traverse both lists together
        while (tempA && tempB)
        {
            if (tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return nullptr;
    }

    // Optimal (Using 2 Pointers)
    // TC : O(N)
    // SC : O(1)
    ListNode *getIntersectionNodeBruteForce(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b)
        {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};