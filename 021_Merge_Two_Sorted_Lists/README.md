#  21. Merge Two Sorted Lists (C – Line by Line Explanation)

##  Problem Statement
You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list.
The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

---

##  Core Idea
Since both linked lists are already sorted, we can merge them by
comparing one node at a time and attaching the smaller value to the
result list. This is similar to the merge step in Merge Sort.

---

##  C Solution with Explanation


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
This is the function provided by LeetCode.
It takes two linked lists and returns the head of the merged list.

    struct ListNode dummy;
    struct ListNode* current = &dummy;
    dummy.next = NULL;


A dummy node is used to simplify the logic.
It helps avoid special cases for the head node.
current is used to build the merged list step by step.

    while (list1 != NULL && list2 != NULL) {


This loop runs while both lists still have nodes to compare.

        if (list1->val <= list2->val) {


The values of the current nodes from both lists are compared.
The smaller value should be placed next in the merged list.

            current->next = list1;
            list1 = list1->next;


If the value in list1 is smaller or equal:

Attach the node from list1

Move list1 to the next node

        } else {
            current->next = list2;
            list2 = list2->next;
        }


Otherwise:

Attach the node from list2

Move list2 to the next node

        current = current->next;


Move the current pointer forward to continue building the merged list.

    }


The loop ends when one of the lists becomes empty.

    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }


If one list still has remaining nodes,
they are directly attached because the list is already sorted.

    return dummy.next;
}


The dummy node is skipped, and the actual head of the merged list is returned.



------------------------------------------------------------------------------------------------------------------------------------------------------

Complexity Analysis

Time Complexity: O(n + m)
Space Complexity: O(1)
