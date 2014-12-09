/*************************************************************************
 * conv: Convert numbers between hex, oct, and dec format
 *
 * (c) 05-2011, Victor Mataré
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage();

int main(int argc, char *argv[]) {
	unsigned long long int number;
	if (argc == 3) {
		char *invalid = calloc(2, sizeof(char));
		if (strcmp(argv[2], "")) {
			number = strtoll(argv[2], &invalid, 0);
			if (*invalid != 0)
				return 2;
		}
		else return 1;


		if (!strcmp(argv[1], "-x")) {
			printf("0x%.2llX\n", number);
		}
		else if (!strcmp(argv[1], "-d")) {
			printf("%lli\n", number);
		}
		else if (!strcmp(argv[1], "-o")) {
			printf("0%llo\n", number);
		}
		else {
			usage();
			return 1;
		}
	}
	else usage();
	return 0;
}

void usage() {
	fprintf(stderr, "convert numbers between hex, oct and dec format\n");
	fprintf(stderr, "Usage: conv -x|-d|-o NUMBER\n");
	fprintf(stderr, "-x, -d and -o set hex/decimal/octal output respectively\n");
	fprintf(stderr, "NUMBER is hex with leading 0x, octal with leading 0.\n");
}
