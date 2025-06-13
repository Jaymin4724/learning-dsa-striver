#include <bits/stdc++.h>
using namespace std;

//? BRUTEFORCE : USING VECTOR/ARRAY
// TC : O(N LOGN)
// SC : O(N)
// (1) Traverse the LinkedList and Store Element's Value in an Array/Vector
// (2) Sort the Vector/Array
// (3) Traverse the Vector/Array and Replace the Element's Value in the LL

//? OPTIMAL : MERGE SORT FOR LINKED LIST !!
// TC : O(N LOGN)
// SC : O(1) , BUT WE ARE USING O(N) SPACE FOR THE RECURSIVE STACK HERE !!
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
    // Function to find the middle node of the linked list
    ListNode *getMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to merge two sorted linked lists
    ListNode *mergeSortedLL(ListNode *left, ListNode *right)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *current = dummy;

        while (left && right)
        {
            if (left->val < right->val)
            {
                current->next = left;
                left = left->next;
            }
            else
            {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        current->next = (left != nullptr) ? left : right;
        return dummy->next;
    }

    // Main function to sort the linked list using Merge Sort
    ListNode *sortList(ListNode *head)
    {
        // Base case
        if (!head || !head->next)
        {
            return head;
        }

        // Split the list into two halves
        ListNode *mid = getMid(head);
        ListNode *right = mid->next;
        mid->next = nullptr;

        // Recursively sort both halves
        ListNode *leftSorted = sortList(head);
        ListNode *rightSorted = sortList(right);

        // Merge the sorted halves
        return mergeSortedLL(leftSorted, rightSorted);
    }
};
