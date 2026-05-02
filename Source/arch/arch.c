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

#define PROGNAME "arch"
#define OPTS "bhluV"

static char USAGE[] =
	"Usage: " PROGNAME " [OPTION]\n"
	"print system architecture\n\n"
	"\t-b\t\tprint bit width (32/64)\n"
	"\t-l\t\tprint available architecture list\n"
	"\t-u\t\tprint userland architecture\n"
	"\t-h\t\tshow this help and exit\n"
	"\t-V\t\tshow version information and exit";

static char ARCH_LIST[] =
	"x86_64\n"
	"i386\n"
	"aarch64\n"
	"armv7l\n"
	"riscv64\n"
	"ppc64le\n"
	"s390x\n"
	"loongarch64\n"
	"mips64\n"
	"sparc64";
	
static int bflag, lflag, sflag, uflag;

int
main(int argc, char *argv[])
{
	int c;
	char *print;
	struct utsname u;
	if (uname(&u) != 0)
		err(1, "uname");
	while ((c = parse_options(OPTS)) != -1) {
		switch (c) {
			case 'b':
				bflag = 1;
				break;
			case 'l':
				lflag = 1;
				break;
			case 'u':
				uflag = 1;
				break;
			case 'h':
				puts(USAGE);
				return EXIT_SUCCESS;
				break;
			case 'V':
				printf("%s %s\n", PROGNAME, PROG_VERSION);
				return EXIT_SUCCESS;
				break;
			default:
				fprintf(stderr, "Try '%s -h' for more information\n", PROGNAME);
				return EXIT_FAILURE;
				break;	
		}
	}

	argc -= optind;
	argv += optind;

	if (argc == 1)
		print = *argv;
	else if (bflag)
		printf("%zu\n", sizeof(void*) * 8);
	else if (lflag)
		print = ARCH_LIST;
	else if (uflag)
		print = USERLAND_ARCH;
	else
		print = u.machine;
	if (!bflag)
		puts(print);
	return EXIT_SUCCESS;
}
