#include "stdio.h"
#include "stdlib.h"

#include "stdio.h"
#include "stdlib.h"

void find_longest_ones(char *arr, int size, int *bit, int *most){
        int count, ones_bit, i, first;

        *most = 0;
	*bit = 0;
        
	first = 1;
        count = 0;

        printf("Array is %d bytes long\n", size);

        for(i=0; i < size * 8; i++){
                if(!(i % 8) && i !=0)
                        printf("  ");

                if((arr[i / 8] >> (i % 8)) & 0x01) {
                        printf("1");
				if(first){
				ones_bit = i;
				first = 0;
                        }

			if(++count > *most) {
				*most = count;
				*bit = ones_bit;
			}       
                }
                else {
                        printf("0");
	                count = 0;
			first = 1;
                }
        
        }
        printf("\n");

        return;
        
}


int main(){

        int size, bit, most;
        char arr[10] = {0xAA, 0xFF, 0x0F, 0x45, 0x34, 0x11, 0x33, 0x88, 0x93, 0x99};
        
	size = 10;

        find_longest_ones(arr, size, &bit, &most);

        printf("Longest run = %d, at bit %d, index %d\n", most, bit, bit/8);

        return 0;
}
