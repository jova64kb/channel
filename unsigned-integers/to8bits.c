#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *tail = NULL;
	uint8_t x = strtol(argv[1], &tail, 10);
	if (*tail != '\0') {
		fprintf(stderr, "invalid input\n");
		return 1;
	}

	uint8_t y = 0x80; /* 1000 0000 */
	
	for (int i = 0; i < 8; i++) {
		if (x & y) {
			printf("1");
		} else {
			printf("0");
		}
		y >>= 1;
	}
	printf("\n");

	return 0;
}

