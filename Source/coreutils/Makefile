#	$SystemONE: (coreutils) Makefile,v 1.0 2026/05/16	#

PROGS=arch basename cat dirname domainname false

all: coreutils obj build

build: obj
	mkdir -p build/
	for i in $(PROGS); do \
		$(CC) -o build/$$i obj/$$i.o obj/coreutils.o -L../libcommon -lcommon; \
	done
obj:
	for i in $(PROGS); do \
		$(CC) -o obj/$$i.o -c $$i.c -I../../Headers; \
	done
coreutils:
	mkdir -p obj/
	$(CC) -o obj/coreutils.o -c coreutils.c -I../../Headers
clean: 
	rm -rf obj build
install:
	for i in $(PROGS); do \
		install -Dm755 build/$$i $(DESTDIR)$(BINDIR)/$$i; \
	done
.PHONY: all $(PROG) build obj clean install
