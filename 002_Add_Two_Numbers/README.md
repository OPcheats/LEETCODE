#  2. Add Two Numbers (C – Line by Line Explanation)

##  Problem Statement
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each node contains a single digit.

Add the two numbers and return the sum as a linked list.

---

##  Core Idea
Since digits are stored in reverse order, we can add the numbers exactly
like manual addition, digit by digit, while keeping track of carry.

---

##  C Solution with Explanation


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
This is the function provided by LeetCode.
It takes two linked lists and returns the head of the result list.

    struct ListNode dummy;
    struct ListNode* current = &dummy;
    dummy.next = NULL;


A dummy node is used to avoid special cases for the head node.
current is used to build the result list step by step.
The final answer will start from dummy.next.

    int carry = 0;


This variable stores the carry generated during addition
when the sum of digits is greater than or equal to 10.

    while (l1 != NULL || l2 != NULL || carry != 0) {


The loop continues as long as:

At least one list still has nodes, OR

There is a carry left to add

This ensures no digit is missed.

        int sum = carry;


We start the sum with the carry from the previous addition.

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

If the first list still has a node:

Add its value to the sum

Move to the next node

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

Same logic as l1.
This also allows handling lists of different lengths safely.

        carry = sum / 10;

If the sum is 10 or more, carry becomes 1.
Otherwise, carry becomes 0.

        struct ListNode* newNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));

A new node is created to store the current digit of the result.

        newNode->val = sum % 10;

Only the last digit of the sum is stored in the node.

        newNode->next = NULL;

The new node is currently the last node in the result list.

        current->next = newNode;
        current = current->next;

The new node is attached to the result list,
and the current pointer is moved forward.

    }

The loop ends after all digits and carry have been processed.

    return dummy.next;
}

The dummy node is skipped, and the actual head of the result list is returned.

⏱ Complexity Analysis

Time Complexity: O(max(n, m))

Space Complexity: O(max(n, m))
