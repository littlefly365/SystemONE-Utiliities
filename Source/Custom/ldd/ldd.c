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

extern char **environ;

struct option longopts[] = {
	{"help", no_argument, 0, HOPT},
	{"version", no_argument, 0, VOPT},
	{0, 0, 0, 0}
};

static void usage(void);

int
main(int argc, char *argv[])
{
	int c, print_name = 0;
	char buf[512];
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

	if (argc == 0) {
		fprintf(stderr, "%s: missing file arguments\n", __progname);
		fprintf(stderr, "Try '%s --help' for more information\n", __progname);
		return FAIL;
	}
	
	if (argc >= 2)
		print_name=1;

	int status = SUCCESS;
	pid_t pid;

	setenv("LD_TRACE_LOADED_OBJECTS", "1", 1);

	for (int i = 0; i < argc; i++) {
		if (print_name)
			printf("%s:\n", argv[i]);
		if (strchr(argv[i], '/') == NULL) {
			snprintf(buf, sizeof(buf), "./%s", argv[i]);
		} else {
			strlcpy(buf, argv[i], sizeof(buf));
		}

		if (access(buf, F_OK) != 0) {
			fprintf(stderr, "%s: %s: No such file or directory\n", __progname, buf);
			status=FAIL;
		} else {
			pid = fork();
			char *args[] = { argv[i], NULL};
			if (pid == -1)
				err(FAIL, "fork");
			if (pid == 0) {
				execvpe(buf, args, environ);
				_exit(FAIL);
			}
			waitpid(pid, NULL, 0);
		}
	}

	return status;
}

static void
usage(void)
{
	printf("Usage: %s [OPTION]... [FILE]...\n"
		"print shared object dependencies\n\n"
		"  --help    show this help and exit\n"
		"  --version show version information and exit\n",
	 __progname);
	exit(SUCCESS);
}
