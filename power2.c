#include "stdio.h"
#include "string.h"
#include "stdlib.h"

int is_power_two(int num) {
	int n = sizeof(num) * 8;
	int cnt, i;
	
	if ((1 << n) & num)	//negative number
		return 0;

	while (i < n) {
		if ((num >> i++) == 1 && cnt <=1)
			cnt++;
		if (cnt > 1)
			return 0;
	}
	
	return 1;
}

int main() {
	char str[16];
	int num;

	scanf("%s", str);
	num = atoi(str);
	printf("%d %s a power of 2", num, is_power_two(num) ? "is" : "is not");
	scanf("%s", str);
	return 0;
}
