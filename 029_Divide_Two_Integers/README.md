 29. Divide Two Integers (C – Line by Line Explanation)

 Problem Statement
Given two integers `dividend` and `divisor`,
divide two integers **without using multiplication, division, or mod operator**.

The division should truncate toward zero.

If the result overflows the 32-bit signed integer range
[-2³¹, 2³¹ − 1], return the boundary value.

---

 Core Idea
Since we cannot use `/`, `*`, or `%`, we simulate division using
**repeated subtraction with bit shifting**.

Bit shifting allows us to subtract large multiples of the divisor
efficiently, reducing time complexity.

---

## 💻 C Solution with Explanation

```c
int divide(int dividend, int divisor) {
```
This is the function signature provided by LeetCode.
It returns the quotient after division.

    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }


This handles the overflow case.
INT_MIN / -1 exceeds the 32-bit integer limit.

    long long a = llabs(dividend);
    long long b = llabs(divisor);


We convert both numbers to positive values using long long
to safely handle edge cases and overflow.

    int result = 0;


This variable will store the final quotient.

    while (a >= b) {


We continue subtracting as long as the dividend
is greater than or equal to the divisor.

        long long temp = b;
        int multiple = 1;


temp stores the shifted divisor value.
multiple keeps track of how many times the divisor is added.

        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }


We keep doubling the divisor using left shift
until it exceeds the remaining dividend.
This speeds up the division process.

        a -= temp;
        result += multiple;


We subtract the largest shifted divisor
and add the corresponding multiple to the result.

    }


The loop ends when the dividend becomes smaller than the divisor.

    if ((dividend < 0) ^ (divisor < 0)) {
        result = -result;
    }


If exactly one of the numbers is negative,
the final result should be negative.

    return result;
}


We return the final quotient after applying the correct sign.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Complexity Analysis

Time Complexity: O(log n)
Space Complexity: O(1)

