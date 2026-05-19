#ifndef _ARGPARSER_H
#define _ARGPARSER_H	1

#include <system.h>
#include <stdbool.h>

enum {
        OK = 0,
        ERROR = 2,
};

typedef struct {
	int shortopt;
	char *longopt;
	char *about;
	bool state;
	char *content;
} flag_t; 

typedef struct {
	flag_t a;
	flag_t b;
	flag_t c;
	flag_t d;
	flag_t e;
	flag_t f;
	flag_t g;
	flag_t h;
	flag_t i;
	flag_t j;
	flag_t k;
	flag_t l;
	flag_t m;
	flag_t n;
	flag_t o;
	flag_t p;
	flag_t q;
	flag_t r;
	flag_t s;
	flag_t t;
	flag_t u;
	flag_t v;
	flag_t w;
	flag_t x;
	flag_t y;
	flag_t z;
} OptionVals;

#define NO_ERRORS	"no_errors"

int ArgsParser(int argc, char *argv[], const char *opts, const char *need_argument, OptionVals *flag);
Noreturn void usage(void);
int print_version(void);

extern int print_error;
extern int optindex;

#endif
