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
