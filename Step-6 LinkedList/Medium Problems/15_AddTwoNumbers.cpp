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
    // You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
    // You may assume the two numbers do not contain any leading zero, except the number 0 itself.

public:
    // TC : O(max(n1,n2))
    // SC : O(max(n1,n2)) --> extra space for new LinkedList
    ListNode *addTwoNumbersMyLogic(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *head = nullptr;
        ListNode *current = nullptr;
        while (temp1 && temp2)
        {
            int value = (temp1->val + temp2->val + carry) % 10;
            ListNode *newNode = new ListNode(value);
            if (!current)
            {
                current = newNode;
                head = current;
            }
            else
            {
                current->next = newNode;
                current = current->next;
            }
            carry = (temp1->val + temp2->val + carry) / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while (!temp1 && temp2)
        {
            int value = (temp2->val + carry) % 10;
            ListNode *newNode = new ListNode(value);
            current->next = newNode;
            current = current->next;
            carry = (temp2->val + carry) / 10;
            temp2 = temp2->next;
        }
        while (!temp2 && temp1)
        {
            int value = (temp1->val + carry) % 10;
            ListNode *newNode = new ListNode(value);
            current->next = newNode;
            current = current->next;
            carry = (temp1->val + carry) / 10;
            temp1 = temp1->next;
        }

        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            current->next = newNode;
            current = current->next;
        }
        return head;
    }

    // efficient version of above code (but same tc and sc)
    ListNode *addTwoNumbersEfficientLogic(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        int carry = 0;
        while ((l1 != NULL || l2 != NULL) || carry)
        {
            int sum = 0;
            if (l1 != NULL)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            carry = sum / 10;
            ListNode *node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};