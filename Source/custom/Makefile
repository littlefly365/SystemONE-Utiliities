#	$SystemONE: (custom-commands) Makefile,v 1.1 2026/05/18		#

PROGS=ldd prime SystemONE-version
ROOT=../..

all: build

build: custom
	mkdir -p $(ROOT)/build
	for i in $(PROGS); do \
		$(CC) -o $(ROOT)/build/$$i $$i.c custom.o $(CPPFLAGS) -I../../Headers -L../libcommon -lcommon; \
	done
custom:
	$(CC) -o custom.o -c custom.c -I../../Headers
clean: 
	for i in $(PROGS); do \
		rm -rf $(ROOT)/build/$$i; \
	done
	rm -rf custom.o
install:
	for i in $(PROGS); do \
		install -Dm755 build/$$i $(DESTDIR)$(BINDIR)/$$i; \
	done
.PHONY: all $(PROG) build custom clean install
