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
#include <ctype.h>
#include <getopt.h>
#include "aux.h"

static struct option longopts[] = {
	{"quiet", no_argument, 0, 'q'},
	{"help", no_argument, 0, HOPT},
	{"version", no_argument, 0, VOPT},
	{0 , 0, 0, 0}
};

static void usage(void);

int
main(int argc, char *argv[])
{
	int c, number;
	int aux = 3, no_prime = 0;
	Options opt = {0};
	setprogname(argv[0]);
	while ((c = getopt_long(argc, argv, "q", longopts, NULL)) != -1) {
		switch (c) {
			case 'q':
				opt.q = 1;
				break;
			case HOPT:
				usage();
				break;
			case VOPT:
				print_version();
				break;
			default:
				fprintf(stderr, "%s: Try '%s --help' for more information\n", __progname, __progname);
				return FAIL;
				break;
			}
		}

	argc -= optind;
	argv += optind;

	if (argc == 0) {
		fprintf(stderr, "%s: missing operand\n", __progname);
		fprintf(stderr, "%s: Try '%s --help' for more information\n", __progname, __progname);
		return FAIL;
	}

	for (int i = 0; argv[0][i] != '\0'; i++) {
		if (!isdigit(argv[0][i]) || atoi(argv[0]) <= 0) {
			fprintf(stderr, "%s: '%s' is not a valid positive number\n", __progname, argv[0]);
			return FAIL;
		}
	}

	number = atoi(argv[0]);

	if (number == 1)
		no_prime = 1;
	else if (number % 2 == 0 &&  number != 2)
		no_prime = 1;

	while (!no_prime && aux < number / aux) {
		if (number % aux == 0)
			no_prime = 1;
		aux+=2;
	}	

	if (!no_prime) {
		if (!opt.q)
			printf("%d is prime\n", number);
		else
			return SUCCESS;
	} else {
		if (!opt.q)
			printf("%d is not prime\n", number);
		else
			return FAIL;
	}

	return SUCCESS;
}

static void
usage(void)
{
	printf("Usage: %s [auxBER] [OPTION]...\n"
	"Print if a auxber is prime or not.\n\n"
	"  -q, --quiet\n only return 0 if auxber is prime else return 1\n"
	"  --help\tshow this help and exit\n"
	"  --version\tshow version information and exit\n",
	__progname);
	exit(SUCCESS);
}
