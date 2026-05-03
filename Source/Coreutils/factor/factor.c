#include "utils.h"

#define PROGNAME "factor"
#define OPTS "hV"

static char USAGE[] =
	"Usage: " PROGNAME " [NUMBER]...\n"
	"or: " PROGNAME " [OPTION]\n"
	"Print the prime factors of each specified integer NUMBER.\n\n"
	"\t-h\t\tshow this help and exit\n"
	"\t-V\t\tshow version information and exit";

static int factor(unsigned long long num);

int
main(int argc, char *argv[])
{
	int c;
	unsigned long long num;
	errno = 0;
	int status = EXIT_SUCCESS;
	while ((c = parse_options(OPTS)) != -1) {
		switch (c) {
			case 'h':
				puts(USAGE);
				return EXIT_SUCCESS;
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
		num = strtoull(argv[i], NULL, 10);
		if (errno == ERANGE)  {
			fprintf(stderr, "%s: %s: number too large\n", PROGNAME, argv[i]);
			status = 1;
			continue;
		 } else 
			factor(num);
	}	

	return status;
}

static int
factor(unsigned long long num)
{
	unsigned long long aux = 3;
	unsigned long long factored = num;

	if (factored < 0) {
		fprintf(stderr, "%s: '%llu' is not a valid positive integer\n", PROGNAME, factored);
		return EXIT_FAILURE;
	}

	printf("%llu:", factored);

	if (factored == 1 || factored == 0) {
		putchar('\n');
		return EXIT_SUCCESS;
	}

	while (factored % 2 == 0) {
		putchar(' ');
		factored = factored / 2;
		printf("2");
	}

	while (factored >= 3) {
		if (factored % aux == 0) {
			putchar(' ');
			factored = factored / aux;
			printf("%llu", aux);
		} else
			aux+=2;
	}	
	
	putchar('\n');
	return EXIT_SUCCESS;
}
