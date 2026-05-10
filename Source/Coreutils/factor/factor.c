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
#include "aux.h"
#include "info.h"

#define PROGNAME "factor"

static char USAGE[] =
	"Usage: " PROGNAME " [NUMBER]... [OPTION]...\n"
	"Print the prime factors of each specified integer NUMBER.\n\n"
	"\t-h\t\tshow this help and exit\n"
	"\t-V\t\tshow version information and exit";

static int factor(unsigned long long num);

int
main(int argc, char *argv[])
{
	int c;
	unsigned long long num;
	errno = 0;
	int status = SUCCESS;
	while ((c = getopt(argc, argv, "hV")) != -1) {
		switch (c) {
			case 'h':
				puts(USAGE);
				return SUCCESS;
				break;
			case 'V':
				print_version(PROGNAME);
				return SUCCESS;
				break;
			default:
				try_msg();
				break;
			}
		}

	argc -= optind;
	argv += optind;
	
	for (int i = 0; i < argc; i++) {
		num = strtoull(argv[i], NULL, 10);
		if (errno == ERANGE)  {
			fprintf(stderr, "%s: %s: number too large\n", PROGNAME, argv[i]);
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
	unsigned long long aux = 3;
	unsigned long long factored = num;

	if (factored < 0) {
		fprintf(stderr, "%s: '%llu' is not a valid positive integer\n", PROGNAME, factored);
		return FAIL;
	}

	printf("%llu:", factored);

	if (factored == 1 || factored == 0) {
		putchar('\n');
		return SUCCESS;
	}

	while (factored % 2 == 0) {
		putchar(' ');
		factored = factored / 2;
		printf("2");
	}

	while (factored >= 3) {
		if (factored % aux == 0) {
			putchar(' ');
			factored = factored / aux;
			printf("%llu", aux);
		} else
			aux+=2;
	}	
	
	putchar('\n');
	return SUCCESS;
}
