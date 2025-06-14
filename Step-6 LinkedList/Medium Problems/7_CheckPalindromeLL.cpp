#include <bits/stdc++.h>
using namespace std;

// BruteForce Approach : Traverse , Store val into Vector, Detect Palindrome in Vector
// TC : O(N)
// SC : O(N)
bool isPalindromeBruteForce1(ListNode *head)
{
    vector<int> data;
    ListNode *temp = head;
    while (temp)
    {
        data.emplace_back(temp->val);
        temp = temp->next;
    }
    int len = data.size();
    int left = 0, right = len - 1;
    while (left < right)
    {
        if (data[left] == data[right])
        {
            left++;
            right--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

// Other BruteForce Approach : using stack (More Efficient)
// TC : O(N)
// SC : O(N)
bool isPalindromeBruteForce2(ListNode *head)
{
    stack<int> s;
    ListNode *temp = head;
    while (temp)
    {
        s.push(temp->val);
        temp = temp->next;
    }
    temp = head;
    while (!s.empty())
    {
        if (s.top() != temp->val)
            return false;
        s.pop();
        temp = temp->next;
    }
    return true;
}

ListNode *reverseLinkedList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *newHead = reverseLinkedList(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

// Optimal Approach :
// (1) find the middle : tortoise and hare algo
// (2) reverse the second half (from element after middle to end) : using recursion / iterative optimal solution
// (3) take two pointers at the start of both halfs and check it
// (4) if not palindrome , reverse second half of the linkedlist and get the original one, return false
// (5) if it is palindrome , reverse second half of the linkedlist and get the original one, return true
// TC : O(N)
// SC : O(1)
bool isPalindromeOptimal(ListNode *head)
{
    // if no ListNode or 1 ListNode
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    // tortoise and hare method : find middle element
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // slow is at middle & reverse the another half of the linkedlist !! (reversing using recursion)
    ListNode *newHead = reverseLinkedList(slow->next);
    ListNode *first = head;     // first half
    ListNode *second = newHead; // second reversed half
    while (second != NULL)
    {
        if (first->val != second->val)
        {
            // Not Palindrome
            // reversing to restoring the original list
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    // Palindrome
    // reversing to restoring the original list
    reverseLinkedList(newHead);
    return true;
}
