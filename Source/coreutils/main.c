#include <stdio.h>
#include <stdlib.h>
#include <Args/ArgParser.h>

int
main(int argc, char *argv[])
{
	OptionVals flag = {0};
	printf("%d\n", optindex);
	if (ArgsParser(argc, argv, "ab", "a", &flag) == 0)
		printf("Todo bien\n");
	else
		printf("Algo salio mal\n");
	printf("%d\n", optindex);
	if (flag.a.state) {
		printf("A\n");
		printf("Argumento de A: %s\n", flag.a.content);
	}
	if (flag.b.state)
		printf("B\n");

	return 0;
}

__attribute__((noreturn)) void
usage(void)
{
	printf("Usage: prog [-ab]\n");
	exit(EXIT_SUCCESS);
}

int
print_version(void)
{
	printf("prog (test) 1.0\n");
	exit(EXIT_SUCCESS);
}
