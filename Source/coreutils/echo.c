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
#include <stdbool.h>
#include <system.h>
#include <ArgParser.h>

int
main(int argc, char *argv[])
{
	OptionVals flag = {0};
	setprogname(argv[0]);
	ArgsParser(argc, argv, "n", "", &flag);
	Next(argc, argv);

	for (int i = 0; i < argc; i++) {
		if (i)
			putchar(' ');
		fputs(argv[i], stdout);
	}

	if (!flag.n.state)
		putchar('\n');
	return EXIT_SUCCESS;
}

Noreturn void
usage(void)
{
	printf("Usage: %s [OPTION] [STRING]...\n"
	"Description: Echo the STRING(s) to standard output.\n"
	"\nGeneral:\n", __progname);
	print_opt("n", "do not print newline");
	printf("\nOptions:\n");
	HELP_USAGE_ABOUT();
	VERSION_USAGE_ABOUT();
	exit(EXIT_SUCCESS);
}
