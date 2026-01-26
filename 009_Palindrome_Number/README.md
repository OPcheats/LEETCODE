#  9. Palindrome Number (C – Line by Line Explanation)

##  Problem Statement
Given an integer `x`, return `true` if `x` is a palindrome,
and `false` otherwise.

A palindrome number reads the same backward as forward.

---

##  Core Idea
A number is a palindrome if its digits are the same when read
from left to right and right to left.

Instead of converting the number to a string, we reverse
only **half of the number** to avoid overflow and extra memory usage.

---

##  C Solution with Explanation


bool isPalindrome(int x) {
This is the function signature provided by LeetCode.
It takes an integer and returns true or false.

    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }


Negative numbers are never palindromes.
Also, numbers ending with 0 (except 0 itself) cannot be palindromes,
because the reversed number would start with 0.

    int reversedHalf = 0;


This variable will store the reversed second half of the number.

    while (x > reversedHalf) {


The loop runs until half of the number is reversed.
This helps avoid reversing the entire number.

        reversedHalf = reversedHalf * 10 + x % 10;


x % 10 extracts the last digit of the number

We add this digit to reversedHalf

        x /= 10;


This removes the last digit from x.

    }


The loop ends when half of the digits have been processed.

    return (x == reversedHalf || x == reversedHalf / 10);
}


If the number has even digits, x should be equal to reversedHalf

If the number has odd digits, the middle digit is ignored by
dividing reversedHalf by 10

If either condition is true, the number is a palindrome.

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Complexity Analysis

Time Complexity: O(log₁₀ n)
Space Complexity: O(1)
