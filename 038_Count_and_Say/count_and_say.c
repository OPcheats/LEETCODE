#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {

    // Base case
    char* result = (char*)malloc(2 * sizeof(char));
    result[0] = '1';
    result[1] = '\0';

    for (int i = 2; i <= n; i++) {

        int len = strlen(result);
        char* temp = (char*)malloc(2 * len + 1); // safe size
        int idx = 0;

        for (int j = 0; j < len; j++) {
            int count = 1;

            while (j + 1 < len && result[j] == result[j + 1]) {
                count++;
                j++;
            }

            // add count
            temp[idx++] = count + '0';
            // add digit
            temp[idx++] = result[j];
        }

        temp[idx] = '\0';
        free(result);
        result = temp;
    }

    return result;
}
