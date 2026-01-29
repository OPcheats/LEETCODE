 27. Remove Element (C – Line by Line Explanation)

 Problem Statement
Given an integer array `nums` and an integer `val`,
remove all occurrences of `val` in-place.

The order of the elements may be changed.
Return the number of elements in `nums` that are not equal to `val`.

The first `k` elements of `nums` should contain the elements
that are not equal to `val`.

---

 Core Idea
We scan the array and keep only the elements
that are **not equal to `val`**.

We use one pointer to track the position where
the next valid element should be placed.

---

 C Solution with Explanation

```c
int removeElement(int* nums, int numsSize, int val) {
```
This is the function signature provided by LeetCode.
It modifies the array in-place and returns the count
of elements not equal to val.

    int k = 0;


k represents the index where the next valid element
(not equal to val) will be stored.

    for (int i = 0; i < numsSize; i++) {


This loop scans every element in the array one by one.

        if (nums[i] != val) {


We check if the current element is not equal to val.

            nums[k] = nums[i];


If the element is valid, we place it at index k.
This overwrites unwanted values in the array.

            k++;


We increment k because one valid element
has been added to the front of the array.

        }


End of the condition block.

    }


End of the loop after scanning the entire array.

    return k;
}


We return k, which represents the number of elements
that are not equal to val.
Only the first k elements of nums are important.

🧪 Example Walkthrough

Input:

nums = [0,1,2,2,3,0,4,2], val = 2


After processing:

nums = [0,1,3,0,4,_,_,_]
k = 5


The order may vary, but the first k elements
do not contain val.
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Complexity Analysis

Time Complexity: O(n)
Space Complexity: O(1)

