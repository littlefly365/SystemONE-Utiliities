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
#include <one_stdlib.h>
#include <ctype.h>
#include <system.h>
#include <ArgParser.h>

int
main(int argc, char *argv[])
{
	int number;
	int aux = 3, no_prime = 0;
	OptionVals flag = {0};
	setprogname(argv[0]);
	ArgsParser(argc, argv, "q", "", &flag);
	Next(argc, argv);

	if (argc == 0) {
		fprintf(stderr, "%s: missing operand\n", __progname);
		try_msg();
		return EXIT_FAILURE;
	}

	for (int i = 0; argv[0][i] != '\0'; i++) {
		if (!isdigit(argv[0][i]) || atoi(argv[0]) <= 0) {
			fprintf(stderr, "%s: '%s' is not a valid positive number\n", __progname, argv[0]);
			return EXIT_FAILURE;
		}
	}

	number = atoi(argv[0]);

	if ((number % 2 == 0 &&  number != 2) || (number == 1))
		no_prime = 1;

	while (!no_prime && aux < number / aux) {
		if (number % aux == 0)
			no_prime = 1;
		aux+=2;
	}	

	if (!no_prime) {
		if (!flag.q.state)
			printf("%d is prime\n", number);
		else
			return EXIT_SUCCESS;
	} else {
		if (!flag.q.state)
			printf("%d is not prime\n", number);
		else
			return EXIT_FAILURE;
	}

	if (!flag.q.state)
		return EXIT_SUCCESS;
}

Noreturn void
usage(void)
{
	printf("Usage: %s [OPTION] NUMBER\n"
	"Description: Print if a number is prime or not.\n"
	"\nOptions:\n", __progname);
	print_opt("q", "only return 0 if number is prime else return 1");
	printf("\nGeneral:\n");
	HELP_USAGE_ABOUT();
	VERSION_USAGE_ABOUT();
	exit(EXIT_SUCCESS);
}
