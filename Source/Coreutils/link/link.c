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

static struct option longopts[] = {
	{"help", no_argument, 0, HOPT},
	{"version", no_argument, 0, VOPT},
	{0, 0, 0, 0}
};

static void usage(void);

int
main(int argc, char *argv[])
{
	int c;
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

	if (argc == 0)
		fprintf(stderr, "%s: missing operand\n", __progname);
	if (argc == 1)
		fprintf(stderr, "%s: missing operand after '%s'\n", __progname, argv[0]);
	if (argc <= 1){
		fprintf(stderr, "Try '%s --help' for more information\n", __progname);
		return FAIL;
	}

	if (link(argv[0], argv[1]) != 0) 
		err(FAIL, "cannot create link '%s' to '%s'", argv[1], argv[0]);

	return SUCCESS;
}

static void
usage(void)
{
	printf("Usage: %s [OPTION]... [FILE1] [FILE2]\n"
	"Call the link function to create a link named FILE2 to an existing FILE1.\n\n"
	"  --help\tshow this help and exit\n"
	"  --version\tshow version information and exit",
	__progname);
	exit(FAIL);
}
