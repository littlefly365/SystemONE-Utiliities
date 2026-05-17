LIBNAME=libcommon

all: libcommon lib

libcommon: 
	@echo "===> libcommon <==="
lib: obj
	$(AR) rcs libcommon.a progname.o basename.o parser.o
obj:
	@$(CC) -c progname.c
	@$(CC) -c basename.c
	@$(CC) -c parser.c -I../../Headers
clean: libcommon
	rm -rf progname.o basename.o parser.o libcommon.a
.PHONY: all libcommon obj clean
