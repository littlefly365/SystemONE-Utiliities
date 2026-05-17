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

#define PROGNAME "tty"
#define OPTS "hsV"

static char USAGE[] =
	"Usage: " PROGNAME " [OPTION]...\n"
	"Print the file name of the terminal connected to standard input.\n\n"
	"\t-s\t\trint nothing, only return an exit status\n"
	"\t-h\t\tshow this help and exit\n"
	"\t-V\t\tshow version information and exit";

DEFINE_FLAG(sflag);

int
main(int argc, char *argv[])
{
	int c;
	char *tty;
	while ((c = getopt(argc, argv, "hsV")) != -1) {
		switch (c) {
			case 'h':
				puts(USAGE);
				return SUCCESS;
				break;
			case 's':
				sflag = FLAG_ON;
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

	tty = ttyname(STDIN_FILENO);

	if (!sflag)
		if (tty)
			puts(tty);
		else
			puts("no a tty");
	if (tty)
		return SUCCESS;
	else
		return FAIL;	
}
