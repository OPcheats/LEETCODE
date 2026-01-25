bool isPalindrome(int x) {

    // Negative numbers or numbers ending with 0 (except 0)
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int reversedHalf = 0;

    // Reverse only half of the number
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // Check for even and odd digit cases
    return (x == reversedHalf || x == reversedHalf / 10);
}

--------------------------------------------------------------------------------------------------------------------------------------------------------------
How i solved this problem --> 
    
Problem Statement:--
Given an integer x, return true if x is a palindrome, and false otherwise.
    
    solution break down-->
            
            Edge case check
            If number is negative → return false
            If number ends with 0 but is not 0 → return false
            Reverse half of the number
            Take last digit using % 10
            Build reversed number
            Remove last digit using / 10
            Compare halves
            For even digits → both halves must be equal
            For odd digits → ignore middle digit and compare

Complexity Analysis-->
    
            Time Complexity: O(log10 n)
            Space Complexity: O(1)
    
