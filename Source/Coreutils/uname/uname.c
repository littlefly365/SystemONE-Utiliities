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

#define PROGNAME "uname"
#define OPTS "adhimnoprsvV"

static const char USAGE[] =
	"Usage: " PROGNAME " [OPTION]... \n" 
	"Print certain system information.  With no OPTION, same as -s.\n\n" 
	"\t-a\t\tprint all information, in the following order\n" 
	"\t-s\t\tprint the kernel name\n" 
	"\t-n\t\tprint the network node hostname\n" 
	"\t-d\t\tprint the domain name\n" 
	"\t-r\t\tprint the kernel release\n" 
	"\t-v\t\tprint the kernel version\n" 
	"\t-m\t\tprint the machine hardware name\n" 
	"\t-o\t\tprint the operating system\n"
	"\t-i\t\tprint the hardware platform (alias of -m)\n"
	"\t-p\t\tprint the processor type (alias of -m)\n"
	"\t-h\t\tshow this help and exit\n"
	"\t-V\t\tshow the version information and exit";

static int dflag, mflag, nflag, oflag, rflag, sflag, vflag;

int
main(int argc, char *argv[])
{
	int c;
	int space = 1;
	struct utsname u;
	if (uname(&u) != 0)
		err(1, "uname");
	while ((c = parse_options(OPTS)) != -1) {
		switch (c) {
			case 'a':
				dflag = mflag = nflag = oflag = rflag = sflag = vflag = 1;
				break;
			case 'd':
				dflag = 1;
				break;
			case 'h':
				puts(USAGE);
				return EXIT_SUCCESS;
				break;
			case 'i':
			case 'p':
			case 'm':
				mflag = 1;
				break;
			case 'n':
				nflag = 1;
				break;
			case 'o':
				oflag = 1;
				break;
			case 'r':
				rflag = 1;
				break;
			case 's':
				sflag = 1;
				break;
			case 'v':
				vflag = 1;
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

	int counter = dflag + mflag + nflag + oflag + rflag + sflag + vflag;

	if (sflag || argc == 1)
		print_and_space(u.sysname, space, counter);
	if (nflag)
		print_and_space(u.nodename, space, counter);
	if (dflag)
		if (strcmp(u.domainname, "(none)") != 0)
			print_and_space(u.domainname, space, counter);
	if (rflag)
		print_and_space(u.release, space, counter);
	if (vflag)
		print_and_space(u.version, space, counter);
	if (mflag)
		print_and_space(u.machine, space, counter);
	if (oflag)
		fputs(OS_NAME, stdout);
	putchar('\n');
}
