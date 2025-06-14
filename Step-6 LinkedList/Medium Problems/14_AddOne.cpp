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
    // Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. The task is to add one to the value represented by the linked list and return the head of a linked list containing the final value.
    // The number will contain no leading zeroes except when the value represented is zero itself.
    // Input: head -> 1 -> 2 -> 3
    // Output: head -> 1 -> 2 -> 4

    // Input: head -> 9 -> 9
    // Output: head -> 1 -> 0 -> 0

    // Input : head -> 1 -> 2 -> 9
    // Output : head -> 1 -> 3 -> 0

    // 2 Approaches : (1) By Reversing (2) By Recursion

    // BRUTEFORCE (By Reversing)
    // TC : O(N)
    // SC : O(1)
    ListNode *reverse(ListNode *head)
    {
        // Reverse Using Recursion
        // base case
        if (!head || !head->next)
            return head;
        // recursive case
        ListNode *newHead = reverse(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
    ListNode *addOneBruteForce(ListNode *head)
    {
        // example 1: head->1->2->3->null
        // example 2: head->9->9->null
        head = reverse(head);
        // null<-1<-2<-3<-head
        // null<-9<-9<-head
        ListNode *temp = head;
        int carry = 1;
        // why ? because we are adding one to the number
        ListNode *prev = nullptr;
        while (temp && carry)
        {
            int sum = temp->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;

            prev = temp;
            temp = temp->next;
        }
        if (carry)
        {
            // null<-1<-0<-0<-head;
            prev->next = new ListNode(carry);
        }
        // head->1->2->4->null
        // head->1->0->0->null
        return reverse(head);
    }

    // OPTIMAL (By Recursion)
    // TC : O(N)
    // SC : O(1)
    int helper(ListNode *node)
    {
        if (!node)
            return 1; // Base case: add 1 at the end

        int carry = helper(node->next);
        int sum = node->val + carry;

        node->val = sum % 10;
        return sum / 10; // return carry
    }
    ListNode *addOneRecursive(ListNode *head)
    {
        int carry = helper(head);

        if (carry)
        {
            // If carry is left, create new head
            ListNode *newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};