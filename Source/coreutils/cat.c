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
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <err.h>
#include <system.h>
#include <ArgParser.h>

int
main(int argc, char *argv[])
{
	int fd, i;
	int status = EXIT_SUCCESS;
	char buf[4096];
	ssize_t size;
	OptionVals flag = {0};
	setprogname(argv[0]);
	ArgsParser(argc, argv, "u", "", &flag);	
	Next(argc, argv);	
	
	do {
		if (argc == 0 || ((strcmp(argv[i], "-")) == 0))
			fd = STDIN_FILENO;
		else
			fd = open(argv[i], O_RDONLY);
		if (fd < 0) {
			warn("%s", argv[i]);
			status = EXIT_FAILURE;
		}
		while ((size = read(fd, buf, sizeof(buf))) > 0)
			write(STDOUT_FILENO, buf, size);
		if (fd != STDIN_FILENO)
			close(fd);
	} while (++i < argc);

	return status;
}

Noreturn void
usage(void)
{
	printf("Usage: %s [FILE]...\n"
	"Description: Concatenate FILE(s) to standard output.\n"
	"\nOptions:\n", __progname);
	print_opt("u", "(ignored)");
	printf("\nGeneral:\n");
	HELP_USAGE_ABOUT();
	VERSION_USAGE_ABOUT();
	exit(EXIT_SUCCESS);
}
