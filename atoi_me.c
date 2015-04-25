#include "stdio.h"
#include "stdlib.h"
#include "math.h"

#define MAX_DIGITS_INT (int)sizeof(int)*8
#define DIGIT(x) ((x & 0xFF) - 0x30)

int atoi_me (char * str) {
        int i,neg, number_int;
		i=0;
		neg = 0;
		number_int = 0;

        if (*str == '-') {
                neg = 1;
				str++;
		}

        while (*str != '\0') {
                if (i > MAX_DIGITS_INT) {
                        fprintf(stderr, "Number too big for integer type (max %d bits)\n", MAX_DIGITS_INT);
                        return -1;
                }
				
                number_int = number_int * 10 + DIGIT(*str);
                str++; i++;
        }

        return neg ? -1 * number_int : number_int;
}

int main() {
        char str[6] = { '-', '3', '5', '1', '7', '\0'};
        int num;

        num = atoi_me(str);
        printf("%d + 5 = %d\n", num, num + 5);
        return 0;
}
