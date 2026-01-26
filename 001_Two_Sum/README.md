#  1. Two Sum (C – Line by Line Explanation)

##  Problem Statement
Given an array of integers `nums` and an integer `target`,
return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order.

---

##  Core Idea
We need to find two different indices `i` and `j` such that:
nums[i] + nums[j] = target.

To keep the solution simple and safe in C, we use a
brute-force approach by checking all possible pairs.

---

##  C Solution with Explanation


int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
This is the function signature provided by LeetCode.
It returns a dynamically allocated array containing two indices.

    int* result = (int*)malloc(2 * sizeof(int));


We allocate memory for the result array because LeetCode
expects the returned array to be allocated dynamically.

    for (int i = 0; i < numsSize; i++) {


The outer loop selects the first element of the pair.

        for (int j = i + 1; j < numsSize; j++) {


The inner loop selects the second element.
We start from i + 1 to ensure we do not use the same element twice.

            if (nums[i] + nums[j] == target) {


We check whether the selected pair adds up to the target value.

                result[0] = i;
                result[1] = j;


If the condition is true, we store the indices of the two numbers.

                *returnSize = 2;
                return result;


We set the return size to 2 and immediately return the result,
since the problem guarantees exactly one solution.

            }


End of the condition block.

        }


End of the inner loop.

    }


End of the outer loop.

    *returnSize = 0;
    return NULL;
}


This return statement is just for safety.
In normal cases, the function will return earlier
because the problem guarantees one valid solution.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Complexity Analysis

Time Complexity: O(n²)
Space Complexity: O(1)
