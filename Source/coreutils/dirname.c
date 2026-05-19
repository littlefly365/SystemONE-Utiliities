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

#define _USE_NULL
#include <stdio.h>
#include <one_stdlib.h>
#include <stdbool.h>
#include <libgen.h>
#include <system.h>
#include <ArgParser.h>

int
main(int argc, char *argv[])
{
	char *dir;
	OptionVals flag = {0};
	setprogname(argv[0]);
	ArgsParser(argc, argv, "z", "", &flag);
	Next(argc, argv);

	if (argc == 0) {
		fprintf(stderr, "%s: missing operand\n", __progname);
		try_msg();
		return EXIT_FAILURE;
	}

	for (int i = 0; i < argc; i++) {
		TRY(dir = dirname(argv[i]), argv[i]);
		fputs(dir, stdout);
		if (flag.z.state)
			putchar('\0');
		else
			putchar('\n');
	}

	return EXIT_SUCCESS;
}

Noreturn void
usage(void)
{
	printf("Usage: %s [OPTION] NAME...\n"
	"Description: Return the directory portion of the given path(s).\n"
	"\nOptions:\n",__progname);
	print_opt("z", "end each output line with NUL, not newline");
	printf("\nGeneral:\n");
	HELP_USAGE_ABOUT();
	VERSION_USAGE_ABOUT();
	exit(EXIT_SUCCESS);
}
