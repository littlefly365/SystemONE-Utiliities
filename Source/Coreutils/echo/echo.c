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

#define PROGNAME "echo"
#define OPTS "eEhnV"

static char USAGE[] =
	"Usage: " PROGNAME " [OPTION]... [STRING]...\n"
	"Echo the STRING(s) to standard output.\n\n"
	"\t-n\t\tdo not print newline\n"
	"\t-e\t\tenable interpretation of backslash escapes\n"
	"\t-E\t\tdisable interpretation of backslash escapes (default)\n"
	"\t-h\t\tshow this help and exit\n"
	"\t-V\t\tshow version information and exit";

static int interpret_escapes(const char *input, char *output);

DEFINE_FLAG(nflag);
DEFINE_FLAG(eflag);

int
main(int argc, char *argv[])
{
	int c, printed = 0;
	char buf[1024];
	while ((c = parse_options(OPTS)) != -1) {
		switch (c) {
			case 'e':
				eflag = FLAG_ON;
				break;
			case 'E':
				eflag = FLAG_OFF;
				break;
			case 'h':
				puts(USAGE);
				return EXIT_SUCCESS;
				break;
			case 'n':
				nflag = 1;
				break;
			case 'V':
				print_version(PROGNAME);
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

	for (int i = 0; i < argc; i++) {
		if (eflag) {
			interpret_escapes(argv[i], buf);
			print_and_space(buf,printed++);
		} else {
			print_and_space(argv[i], printed++);
		}
	}

	if (!nflag)
		putchar('\n');
	return EXIT_SUCCESS;
}

static int
interpret_escapes(const char *input, char *output)
{
	const char *string = input;
	char *dest = output;

	while (*string) {
		if (*string == '\\' && *(string + 1)) {
			switch (*(string + 1)) {
				case 'n':
					*dest++ = '\n';
					string += 2;
					break;
				case 't':
					*dest++ = '\t';
					string += 2;
					break;
				case '\\':
					*dest++ = '\\';
					string += 2;
					break;
				default:
					*dest++ = *string++;
					break;
			}
	} else {
		*dest++ = *string++;
		}
	}
	dest = '\0';
	return EXIT_SUCCESS;
}
