#include "utils.h"

#define PROGNAME "factor"
#define OPTS "hV"

static char USAGE[] =
	"Usage: " PROGNAME " [NUMBER]...\n"
	"or: " PROGNAME " [OPTION]\n"
	"Print the prime factors of each specified integer NUMBER.\n\n"
	"\t-h\t\tshow this help and exit\n"
	"\t-V\t\tshow version information and exit";

static int factor(int num);
static int verify_num(char *stringing);

int
main(int argc, char *argv[])
{
	int c, num;
	int status = EXIT_SUCCESS;
	while ((c = parse_options(OPTS)) != -1) {
		switch (c) {
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
	
	for (int i = 0; i < argc; i++) {
		if (verify_num(argv[i])) {
			fprintf(stderr, "%s: '%s' is not a valid positive integer\n", PROGNAME, argv[i]);
			status = EXIT_FAILURE;
		} else 
			factor(atoi(argv[i]));
	}

	return status;
}

static int
factor(int num)
{
	int aux = 3;
	int factored = num;

	if (factored < 0) {
		fprintf(stderr, "%s: '%d' is not a valid positive integer\n", PROGNAME, factored);
		return EXIT_FAILURE;
	}

	printf("%d:", factored);

	if (factored == 1 || factored == 0) {
		putchar('\n');
		return EXIT_SUCCESS;
	}

	if (factored % 2 == 0) {
		putchar(' ');
		factored = factored / aux;
		printf("%d", aux);
	}

	while (factored > 1) {
		if (factored % aux == 0) {
			putchar(' ');
			factored = factored / aux;
			printf("%d", aux);
		} else
			aux+=2;
	}	
	
	putchar('\n');
	return EXIT_SUCCESS;
}

static int
verify_num(char *string)
{
	if (string == NULL || *string == '\0') 
		return EXIT_SUCCESS; 

	int start = 0;
	if (string[0] == '-') { 
		if (strlen(string) == 1) 
			return EXIT_FAILURE; 
		start = 1;
	}

	for (int i = start; i < strlen(string); i++) {
		if (!isdigit(string[i]))
			return EXIT_FAILURE; 
		}
	return EXIT_SUCCESS;
}
