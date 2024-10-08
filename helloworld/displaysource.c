#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
	FILE *f = fopen("./helloworld.c", "r");
	if (f == NULL) {
		fprintf(stderr, "fopen: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	int c = 0;
	while (c != EOF) {
		c = fgetc(f);
		switch (c) {
			case -1:
				printf("EOF = %i", c);
				break;
			case 9:
				printf("\\t = %i", c);
				break;
			case 10:
				printf("\\n = %i", c);
				break;
			case 32:
				printf("SP = %i", c);
				break;
			default:
				printf("%c = %i", c, c);
		}
		printf("\n");
	}

	if (fclose(f) == EOF) {
		fprintf(stderr, "fclose: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

