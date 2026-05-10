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

#define PROGNAME "uname"
#define OPTS "ahimnoprsvV"

static const char USAGE[] =
	"Usage: " PROGNAME " [OPTION]... \n" 
	"Print certain system information.  With no OPTION, same as -s.\n\n" 
	"\t-a\t\tprint all information, in the following order\n" 
	"\t-s\t\tprint the kernel name\n" 
	"\t-n\t\tprint the network node hostname\n" 
	"\t-r\t\tprint the kernel release\n" 
	"\t-v\t\tprint the kernel version\n" 
	"\t-m\t\tprint the machine hardware name\n" 
	"\t-o\t\tprint the operating system\n"
	"\t-i\t\tprint the hardware platform (alias of -m)\n"
	"\t-p\t\tprint the processor type (alias of -m)\n"
	"\t-h\t\tshow this help and exit\n"
	"\t-V\t\tshow the version information and exit";

DEFINE_FLAG(mflag);
DEFINE_FLAG(nflag);
DEFINE_FLAG(oflag);
DEFINE_FLAG(rflag);
DEFINE_FLAG(sflag);
DEFINE_FLAG(vflag);

int
main(int argc, char *argv[])
{
	int c, space = 0;
	struct utsname u;
	if (uname(&u) != 0) {
		warn("uname");
		return FAIL;
	}

	while ((c = getopt(argc, argv, "ahimnoprsvV")) != -1) {
		switch (c) {
			case 'a':
				mflag = nflag = oflag = rflag = sflag = vflag = FLAG_ON;
				break;
			case 'h':
				puts(USAGE);
				return SUCCESS;
				break;
			case 'i':
			case 'p':
			case 'm':
				mflag = FLAG_ON;
				break;
			case 'n':
				nflag = FLAG_ON;
				break;
			case 'o':
				oflag = FLAG_ON;
				break;
			case 'r':
				rflag = FLAG_ON;
				break;
			case 's':
				sflag = FLAG_ON;
				break;
			case 'v':
				vflag = FLAG_ON;
				break;
			case 'V':
				print_version(PROGNAME);
				return SUCCESS;
				break;
			default:
				fprintf(stderr, "Try '%s -h' for more information\n", PROGNAME);
				return FAIL;
				break;
		}
	}

	if (sflag || argc == 1)
		print_and_space(u.sysname, space++);
	if (nflag)
		print_and_space(u.nodename, space++);
	if (rflag)
		print_and_space(u.release, space++);
	if (vflag)
		print_and_space(u.version, space++);
	if (mflag)
		print_and_space(u.machine, space++);
	if (oflag)
		print_and_space(OS_NAME, space++);
	putchar('\n');

	return SUCCESS;
}
