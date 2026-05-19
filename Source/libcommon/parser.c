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
#include <one_stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <libgen.h>
#include <ArgParser.h>

#ifdef _HAVE_GETPROGNAME
#define PROGNAME	getprogname()
#else
#define PROGNAME	basename(argv[0])
#endif

int print_error = 1;
int optindex = 1;

int
ArgsParser(int argc, char *argv[], const char *opts, const char *need_arguments, OptionVals *flag)
{
	bool posix = false;
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			if (argv[i][0] != '-')
				posix = true;
			if (argv[i][0] == '-') {
				if (strcmp(argv[i], "--") == 0){
					optindex++;
					return OK;
				}
				else if(argv[i][j + 1] == '\0')
					return OK;
				else if (strcmp(argv[i], "--help") == 0) {
					usage();
					exit(1);
				}

				else if (strcmp(argv[i], "--version") == 0) {
					print_version();
					exit(1);
				}

				if (j == 0) {
					if (!posix)
						optindex++;
					j++;
				}
				if (strcmp(opts, NO_ERRORS) != 0) {
					if (strrchr(opts, argv[i][j]) == NULL) {
						if (print_error) {
							fprintf(stderr, "%s: unrecognized option '-%c'\n", PROGNAME, argv[i][j]);
							try_msg();
						}
						exit(ERROR);
					}
				}

				switch (argv[i][j]) {
					case 'a':
						if (strrchr(need_arguments, 'a') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->a.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->a.state = true;
						break;
					case 'b':
						if (strrchr(need_arguments, 'b') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->b.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->b.state = true;
						break;
					case 'c':
						if (strrchr(need_arguments, 'c') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->c.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->c.state = true;
						break;
					case 'd':
						if (strrchr(need_arguments, 'd') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->d.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->d.state = true;
						break;
					case 'e':
						if (strrchr(need_arguments, 'e') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->e.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->e.state = true;
						break;
					case 'f':
						if (strrchr(need_arguments, 'f') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->f.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->f.state = true;
						break;
					case 'g':
						if (strrchr(need_arguments, 'g') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->g.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->g.state = true;
						break;
					case 'h':
						if (strrchr(need_arguments, 'h') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->h.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->h.state = true;
						break;
					case 'i':
						if (strrchr(need_arguments, 'i') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->i.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->i.state = true;
						break;
					case 'j':
						if (strrchr(need_arguments, 'j') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->j.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->j.state = true;
						break;
					case 'k':
						if (strrchr(need_arguments, 'k') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->k.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->k.state = true;
						break;
					case 'l':
						if (strrchr(need_arguments, 'l') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->l.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->l.state = true;
						break;
					case 'm':
						if (strrchr(need_arguments, 'm') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->m.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->m.state = true;
						break;
					case 'n':
						if (strrchr(need_arguments, 'n') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->n.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						if (!posix)
							flag->n.state = true;
						break;
					case 'o':
						if (strrchr(need_arguments, 'o') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->o.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->o.state = true;
						break;
					case 'p':
						if (strrchr(need_arguments, 'p') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->p.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->p.state = true;
						break;
					case 'q':
						if (strrchr(need_arguments, 'q') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->q.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->q.state = true;
						break;
					case 'r':
						if (strrchr(need_arguments, 's') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->r.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->r.state = true;
						break;
					case 's':
						if (strrchr(need_arguments, 's') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->s.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->s.state = true;
						break;
					case 't':
						if (strrchr(need_arguments, 't') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->t.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->t.state = true;
						break;
					case 'u':
						if (strrchr(need_arguments, 'u') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->u.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->u.state = true;
						break;
					case 'v':
						if (strrchr(need_arguments, 'v') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->v.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->v.state = true;
						break;
					case 'w':
						if (strrchr(need_arguments, 'w') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->w.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->w.state = true;
						break;
					case 'x':
						if (strrchr(need_arguments, 'x') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->x.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->x.state = true;
						break;
					case 'y':
						if (strrchr(need_arguments, 'y') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->y.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->y.state = true;
						break;
					case 'z':
						if (strrchr(need_arguments, 'z') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->z.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->z.state = true;
						break;
					default:
						break;
				}
			} else
				continue;
		}
	}

	return OK;
}

