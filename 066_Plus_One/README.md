 66. Plus One (C – Line by Line Explanation)

 Problem Statement
You are given a large integer represented as an integer array `digits`,
where each `digits[i]` is a single digit of the number.

The digits are ordered from most significant to least significant.
The number does not contain any leading zeros.

Increment the number by one and return the resulting array of digits.

---

 Core Idea
We add **1** starting from the **last digit** (least significant digit),
just like manual addition.

There are two cases:
1. If the digit is less than 9 → simply add 1 and return
2. If the digit is 9 → it becomes 0 and we carry 1 to the left

If all digits are 9, we need a **new array** with one extra digit.

---

 C Solution with Explanation

```c
int* plusOne(int* digits, int digitsSize, int* returnSize) {
```

This is the function signature provided by LeetCode.
It returns a new array and sets the size using returnSize.

    for (int i = digitsSize - 1; i >= 0; i--) {


We start from the last digit because addition begins
from the least significant digit.

        if (digits[i] < 9) {


If the current digit is less than 9,
we can safely add 1 without any carry.

            digits[i]++;
            *returnSize = digitsSize;
            return digits;


We increment the digit, set the return size,
and return the original array.

        }


End of the condition block.

        digits[i] = 0;


If the digit is 9, it becomes 0 after adding 1,
and we continue the carry to the next digit.

    }


The loop ends if all digits were 9.

    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));


If all digits were 9, we need a new array
with one extra digit.

    result[0] = 1;


The most significant digit becomes 1
(e.g., 999 + 1 = 1000).

    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;
    }


All remaining digits are set to 0.

    *returnSize = digitsSize + 1;
    return result;
}


We update the size and return the new array.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
 Complexity Analysis

Time Complexity: O(n)

Space Complexity: O(n) (only when all digits are 9)
