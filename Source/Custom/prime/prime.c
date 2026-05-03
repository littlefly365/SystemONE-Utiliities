/*
*  Copyright (c) 2026, littlefly365
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are met:
*
*  1. Redistributions of source code must retain the above copyright notice, this
*     list of conditions and the following disclaimer.
*
*  2. Redistributions in binary form must reproduce the above copyright notice,
*     this list of conditions and the following disclaimer in the documentation
*     and/or other materials provided with the distribution.
*
*  3. Neither the name of the copyright holder nor the names of its
*     contributors may be used to endorse or promote products derived from
*     this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
*  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
*  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
*  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
*  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
*  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*  (BSD 3-Clause License)
*/

#include "utils.h"

#define PROGNAME "prime"
#define OPTS "hV"

static char USAGE[] =
	"Usage: " PROGNAME " [NUMBER]\n"
	"or: " PROGNAME " [OPTION]\n"
	"Print if a number is prime or not.\n\n"
	"\t-h\t\tshow this help and exit\n"
	"\t-V\t\tshow version information and exit";

int
main(int argc, char *argv[])
{
	int c;
	int prime, num = 3, not_is_prime;
	while ((c = parse_options(OPTS)) != -1) {
		switch (c) {
			case 'h':
				puts(USAGE);	
				return EXIT_SUCCESS;
				break;
			case 'V':
				print_version(PROGNAME);
				return EXIT_SUCCESS;
				break;
			default:
				fprintf(stderr, "Try '%s -h' for more information\n", PROGNAME);
				return EXIT_FAILURE;
				break;
			}
		}

	argc -= optind;
	argv += optind;

	for (int i = 0; argv[0][i] != '\0'; i++) {
		if (!isdigit(argv[0][i]) || atoi(argv[0]) < 0) {
			fprintf(stderr, "%s: '%s' is not a valid positive number\n", PROGNAME, argv[0]);
			return EXIT_FAILURE;
		}
	}

	prime = atoi(argv[0]);

	if (prime <= 1 || (prime % 2 == 0 && prime != 2)) {
		printf("%s is not prime\n", argv[0]);
		return EXIT_SUCCESS;
	}
	
	while (!not_is_prime && num <= prime / num) {
		if (prime % num == 0)
			not_is_prime = 1;
		num+=2;
	}	

	if (!not_is_prime)
		printf("%d is prime\n", prime);
	else
		printf("%d is not prime\n", prime);

	return EXIT_SUCCESS;
}
