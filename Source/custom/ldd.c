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

#define _GNU_SOURCE
#include <sys/wait.h>
#include <stdio.h>
#include <one_stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>
#include <system.h>
#include <ArgParser.h>

int
main(int argc, char *argv[])
{
	int print_name = 0;
	char buf[512];
	OptionVals flag = {0};
	setprogname(argv[0]);
	ArgsParser(argc, argv, "", "", &flag);
	Next(argc, argv);

	if (argc == 0) {
		fprintf(stderr, "%s: missing file arguments\n", __progname);
		try_msg();
		return EXIT_FAILURE;
	}
	
	if (argc > 1)
		print_name=1;

	int status = EXIT_SUCCESS;
	pid_t pid;

	setenv("LD_TRACE_LOADED_OBJECTS", "1", 1);

	for (int i = 0; i < argc; i++) {
		if (print_name)
			printf("%s:\n", argv[i]);
		if (strchr(argv[i], '/') == NULL)
			snprintf(buf, sizeof(buf), "./%s", argv[i]);
		else
			strlcpy(buf, argv[i], sizeof(buf));

		if (access(buf, F_OK) != 0) {
			fprintf(stderr, "%s: %s: No such file or directory\n", __progname, buf);
			status=EXIT_FAILURE;
		} else {
			pid = fork();
			char *args[] = { argv[i], NULL };
			if (pid == -1)
				err(EXIT_FAILURE, "%s", argv[i]);
			if (pid == 0) {
				execvpe(buf, args, environ);
				_exit(EXIT_FAILURE);
			}
			waitpid(pid, NULL, 0);
		}
	}

	return status;
}

Noreturn void
usage(void)
{
	printf("Usage: %s [FILE]...\n"
	"Description: Print shared object dependencies.\n"
	"\nGeneral:\n", __progname);
	HELP_USAGE_ABOUT();
	VERSION_USAGE_ABOUT();
	exit(EXIT_SUCCESS);
}
