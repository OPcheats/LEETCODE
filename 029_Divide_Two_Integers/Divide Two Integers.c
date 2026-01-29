int divide(int dividend, int divisor) {

    // Handle overflow case
    if (dividend == -2147483648 && divisor == -1) {
        return 2147483647;
    }

    int sign = 1;
    if ((dividend < 0 && divisor > 0) || 
        (dividend > 0 && divisor < 0)) {
        sign = -1;
    }

    long long a = dividend;
    long long b = divisor;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    long long result = 0;

    while (a >= b) {
        long long temp = b;
        long long count = 1;   

        while (a >= (temp << 1)) {
            temp = temp << 1;
            count = count << 1;
        }

        a = a - temp;
        result = result + count;
    }

    return (int)(sign * result);
}
