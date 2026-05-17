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

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include "aux.h"

static struct option longopts[] = {
	{"help", no_argument, 0, HOPT},
	{"version", no_argument, 0, VOPT},
	{0, 0, 0, 0}
};

static int factor(unsigned long long num);
static void usage(void);

int
main(int argc, char *argv[])
{
	int c;
	unsigned long long num;
	errno = 0;
	int status = SUCCESS;
	setprogname(argv[0]);
	while ((c = getopt_long(argc, argv, "", longopts, NULL)) != -1) {
		switch (c) {
			case HOPT:
				usage();
				break;
			case VOPT:
				print_version();
				break;
			default:
				fprintf(stderr, "Try '%s --help' for more information\n", __progname);
				return FAIL;
				break;
			}
		}

	argc -= optind;
	argv += optind;
	
	for (int i = 0; i < argc; i++) {
		num = strtoull(argv[i], NULL, 10);
		if (num == 0) {
			fprintf(stderr, "%s: '0' is not a valid positive integer\n", __progname);
			status=1;
			continue;
		}
		if (errno == ERANGE)  {
			fprintf(stderr, "%s: %s: number too large\n", __progname, argv[i]);
			status = 1;
			continue;
		} else
			factor(num);
	}	

	return status;
}

static int
factor(unsigned long long num)
{
	unsigned long long factored = num;
	unsigned long long i;
	printf("%llu:", factored);

	while (factored % 2 == 0) { printf(" 2"); factored /= 2; }
	while (factored % 3 == 0) { printf(" 3"); factored /= 3; }
	while (factored % 5 == 0) { printf(" 5"); factored /= 5; }
	while (factored % 7 == 0) { printf(" 7"); factored /= 7; }

	for (i = 11; i <= factored / i; i+=2) {
		if (factored % i == 0) {
			printf(" %llu", i);
			factored /= i;
		} else {
			continue;
		}
	}	

	if (factored > 1)
		printf(" %llu", factored);
	putchar('\n');
	return SUCCESS;
}

static void
usage(void)
{
	printf("Usage: %s [OPTION]... [NUMBER]...\n"
	"Print the prime factors of each specified integer NUMBER.\n\n"
	"  --help\tshow this help and exit\n"
	"  --version\tshow version information and exit\n", 
	__progname);
	exit(SUCCESS);
}

