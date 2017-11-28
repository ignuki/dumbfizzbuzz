#include <stdio.h>

int main(void) {
	unsigned char a[] = "fizzbuzz\0", b[] = {0, 0, 0, 0};
	unsigned char *p = a, *const q = a + 4;
	int c, i = 100;
j1:
	p = a + (!!(--i % 3) * 4);
	*q = !(i % 5) * 98;
	if (*p) goto j3;
	*(c = i, p = b + 2) = 10;
j2:
	*--p = 48 + c % 10;
	c /= 10;
	if (c) goto j2;
	fwrite(p, 3 - (p - b), 1, stdout);
	if (i > 1) goto j1;
	return 0;
j3:
	fwrite(p, 8 >> (1 - !!(*p - *q) + !*q), 1, stdout);
	fputc('\n', stdout);
	goto j1;
}
