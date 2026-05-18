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

#ifndef _SYSTEM_H
#define _SYSTEM_H	1

#include <err.h>

#ifndef	BOLD
#define	BOLD	"\x1B[1m"
#endif

#ifndef	REG
#define	REG	"\x1B[0m"
#endif

#ifndef Noreturn
#define Noreturn	__attribute__((noreturn))
#endif

#ifndef HELP_USAGE_ABOUT
#define HELP_USAGE_ABOUT() printf("%s   --help%s        Print help information\n", BOLD, REG)
#endif

#ifndef VERSION_USAGE_ABOUT
#define VERSION_USAGE_ABOUT() printf("%s   --version%s     Print version\n", BOLD, REG)
#endif

#ifndef try_msg
#define try_msg()	\
	fprintf(stderr, "Try '%s --help' for more information.\n", __progname);
#endif

#ifndef TRY_INT
#define TRY_INT(func, msg)	\
	if ((func) != 0)	\
		err(EXIT_FAILURE, "%s", msg)
#endif

#ifndef TRY_NULL
#define TRY_NULL(func, msg)	\
	if ((func) == NULL)	\
		err(EXIT_FAILURE, "%s", msg)
#endif

#if (!defined(_USE_NULL) && !defined(_USE_INT)) || defined(_USE_INT)
#define TRY TRY_INT
#elif defined(_USE_NULL)
#define TRY TRY_NULL 
#endif

#define COREUTILS_AUTHORS	"littlefly365"

#define Next(argc, argv)	\
	argc -= optindex;	\
	argv += optindex

#define print_opt(opt, about)	\
	printf("%s   -%s%s            %s\n", BOLD, opt, REG, about)

char *one_basename(const char *string);

#endif
