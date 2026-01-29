 26. Remove Duplicates from Sorted Array (C – Line by Line Explanation)

 Problem Statement
Given an integer array `nums` sorted in non-decreasing order,
remove the duplicates **in-place** such that each unique element
appears only once.

The relative order of the elements must be kept the same.

Return the number of unique elements `k`.
The first `k` elements of `nums` should contain the unique values.

---

 Core Idea
Because the array is already **sorted**, all duplicate elements
will appear next to each other.

We can use a **two-pointer approach**:
- One pointer keeps track of the position of the last unique element
- The other pointer scans the array

---

 C Solution with Explanation


``` int removeDuplicates(int* nums, int numsSize) { ```

This is the function signature provided by LeetCode.
It modifies the array in-place and returns the count of unique elements.

    if (numsSize == 0) {
        return 0;
    }


If the array is empty, there are no elements,
so we return 0.

    int k = 1;


k represents the count of unique elements found so far.
The first element is always unique, so we start from 1.

    for (int i = 1; i < numsSize; i++) {


We start the loop from index 1 because the first element
is already considered unique.

        if (nums[i] != nums[k - 1]) {


If the current element is different from the last unique element,
it means we found a new unique value.

            nums[k] = nums[i];


We place this new unique value at index k
to maintain the correct order.

            k++;


We increment k because we have found one more unique element.

        }


End of the condition block.

    }


End of the loop after scanning the entire array.

    return k;
}


We return k, which represents the number of unique elements.
The first k positions of nums now contain the correct result.

🧪 Example Walkthrough

Input:

nums = [0,0,1,1,1,2,2,3,3,4]


After processing:

nums = [0,1,2,3,4,_,_,_,_,_]
k = 5


Only the first k elements matter.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Complexity Analysis:-

Time Complexity: O(n)
Space Complexity: O(1)
