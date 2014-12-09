#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char error;

uint32_t ip2int(const char *ip) {
	int t[4], n;
	uint32_t i;
	uint8_t *b = (uint8_t *) &i;

	t[0] = t[1] = t[2] = t[3] = 0;
	sscanf(ip, "%d.%d.%d.%d", t+3, t+2, t+1, t);
	for (n = 3; n >= 0; n--) {
		if (t[n] < 0 || t[n] > 255) {
			error = 1;
			return 0;
		}
		else b[n] = (uint32_t) t[n];
	}
	return i;
}

int main(int argc, char **argv) {
	uint32_t i, start, end;
	uint8_t *b = (uint8_t *) &i;
	error = 0;

	if (argc < 2) {
		printf("Usage: %s FROM TO\n", argv[0]);
		return 1;
	}
	start = ip2int(argv[1]);
	end = ip2int(argv[2]);
	if (error) return error;
	for (i = start; i <= end; i++)
		printf("%d.%d.%d.%d\n", b[3], b[2], b[1], b[0]);
	return 0;
}

