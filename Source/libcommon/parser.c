#include <stdio.h>
#include <stdlib.h>
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
ArgsParser(int argc, char *argv[], const char *opts, const char *required_arguments, OptionVals *flag)
{
	for (int i = 0; i < argc; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			if (argv[i][0] == '-') {
				if ((strcmp(argv[i], "--") == 0) || argv[i][j + 1] == '\0')
					return OK;
				else if (strcmp(argv[i], "--help") == 0) {
					usage();
					exit(ERROR);
				}

				else if (strcmp(argv[i], "--version") == 0) {
					print_version();
					exit(ERROR);
				}

				if (j == 0) {
					optindex++;
					j++;
				}
				if (strcmp(opts, NO_ERRORS) != 0) {
					if (strrchr(opts, argv[i][j]) == NULL) {
						if (print_error)
							fprintf(stderr, "%s: unrecognized option '-%c'\n", PROGNAME, argv[i][j]);
						exit(UNKNOWN);
					}
				}

				switch (argv[i][j]) {
					case 'a':
						if (strrchr(required_arguments, 'a') != NULL) {
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
						if (strrchr(required_arguments, 'b') != NULL) {
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
						if (strrchr(required_arguments, 'c') != NULL) {
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
						if (strrchr(required_arguments, 'd') != NULL) {
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
						if (strrchr(required_arguments, 'e') != NULL) {
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
						if (strrchr(required_arguments, 'f') != NULL) {
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
						if (strrchr(required_arguments, 'g') != NULL) {
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
						if (strrchr(required_arguments, 'h') != NULL) {
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
						if (strrchr(required_arguments, 'i') != NULL) {
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
						if (strrchr(required_arguments, 'j') != NULL) {
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
						if (strrchr(required_arguments, 'k') != NULL) {
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
						if (strrchr(required_arguments, 'l') != NULL) {
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
						if (strrchr(required_arguments, 'm') != NULL) {
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
						if (strrchr(required_arguments, 'n') != NULL) {
							if (argv[i + 1] != NULL && argv[i + 1][0] != '-')
								flag->n.content = argv[i + 1];
							else {
								if (print_error)
									fprintf(stderr, "%s: option requires an argument '-%c'\n", PROGNAME, argv[i][j]);
								exit(ERROR);
							}
						}
						flag->n.state = true;
						break;
					case 'o':
						if (strrchr(required_arguments, 'o') != NULL) {
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
						if (strrchr(required_arguments, 'p') != NULL) {
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
						if (strrchr(required_arguments, 'q') != NULL) {
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
						if (strrchr(required_arguments, 's') != NULL) {
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
						if (strrchr(required_arguments, 's') != NULL) {
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
						if (strrchr(required_arguments, 't') != NULL) {
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
						if (strrchr(required_arguments, 'u') != NULL) {
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
						if (strrchr(required_arguments, 'v') != NULL) {
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
						if (strrchr(required_arguments, 'w') != NULL) {
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
						if (strrchr(required_arguments, 'x') != NULL) {
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
						if (strrchr(required_arguments, 'y') != NULL) {
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
						if (strrchr(required_arguments, 'z') != NULL) {
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

